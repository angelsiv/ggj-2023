// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeed.h"

#include "ProjectSeedsProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseSeed::ABaseSeed()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	ShipMeshComponent->SetupAttachment(RootComponent);
	//RootComponent = CapsuleComponent;
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.2f;
	bCanFire = true;

	MaxHealthPoints = 100.0f;
	MaxActionPoints = 1;
	ResetPoints();
}

void ABaseSeed::ResetPoints()
{
	HealtPoints = MaxHealthPoints;
	ActionPoints = MaxActionPoints;
}

// Called when the game starts or when spawned
void ABaseSeed::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseSeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseSeed::FireShot()
{
	if (bCanFire == true)
	{
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + GetActorRotation().RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AProjectSeedsProjectile>(SpawnLocation, GetActorRotation());
		}

		bCanFire = false;
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ABaseSeed::ShotTimerExpired,
			FireRate);

		// try and play the sound if specified
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		bCanFire = false;
	}
}

void ABaseSeed::ShotTimerExpired()
{
	bCanFire = true;
}

void ABaseSeed::SetHealthToFull()
{
	HealtPoints = MaxHealthPoints;
	CheckHealth();
}

void ABaseSeed::SetHealthToZero()
{
	HealtPoints = 0.0f;
	CheckHealth();
}

void ABaseSeed::Heal(float Value)
{
	HealtPoints = FMath::Min(MaxHealthPoints, HealtPoints + Value);
	CheckHealth();
}

void ABaseSeed::CheckHealth()
{
	if (HealtPoints <= 0.0f)
	{
		HandleDeath();
	}
}

void ABaseSeed::UpgradeMaxHealthPoints(float Value)
{
	MaxHealthPoints += Value;
	HealtPoints = MaxHealthPoints;
}

void ABaseSeed::UpgradeMaxActionPoints(int Value)
{
	MaxActionPoints += Value;
	ActionPoints = MaxActionPoints;
}

bool ABaseSeed::CanSpendActionPoints(int Value)
{
	if (ActionPoints >= Value)
	{
		ActionPoints -= Value;
		return true;
	}

	return false;
}

void ABaseSeed::HandleDeath()
{
	if (DeathRewardActor)
	{
		GetWorld()->SpawnActor<AActor>(DeathRewardActor, GetActorLocation(), GetActorRotation());
	}

	Destroy();
}

void ABaseSeed::SetMoveSpeed(float Value)
{
	this->MoveSpeed = Value;
}
float ABaseSeed::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	const float PreviousHealth = HealtPoints;
	HealtPoints -= Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	CheckHealth();

	return PreviousHealth - HealtPoints;
}
