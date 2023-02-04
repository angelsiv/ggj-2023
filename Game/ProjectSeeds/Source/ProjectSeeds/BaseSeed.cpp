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
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.2f;
	bCanFire = true;
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
	Health = MaxHealth;
	CheckHealth();
}

void ABaseSeed::SetHealthToZero()
{
	Health = 0.0f;
	CheckHealth();
}

void ABaseSeed::Heal(float Value)
{
	Health = FMath::Min(MaxHealth, Health + Value);
	CheckHealth();
}

void ABaseSeed::CheckHealth()
{
	if (Health <= 0.0f)
	{
		HandleDeath();
	}
}

void ABaseSeed::HandleDeath()
{
	Destroy();
}

void ABaseSeed::SetMoveSpeed(float Value)
{
	this->MoveSpeed = Value;
}
float ABaseSeed::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	const float PreviousHealth = Health;
	Health -= Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	CheckHealth();

	return PreviousHealth - Health;
}
