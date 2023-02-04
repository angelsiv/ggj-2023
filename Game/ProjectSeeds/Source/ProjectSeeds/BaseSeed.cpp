// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeed.h"

#include "AbilityComponent.h"
#include "ProjectSeedsProjectile.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseSeed::ABaseSeed()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(
		TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	ShipMeshComponent->SetupAttachment(RootComponent);

	AbilityComponent = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbiilityComponent"));
	//RootComponent = CapsuleComponent;

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(
		TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.2f;
	bCanFire = true;

	// Health
	MaxHealthPoints = 100.0f;

	HealthBarComponent = CreateDefaultSubobject<UHealthBarComponent>(TEXT("HealthUIComponent"));
	HealthBarComponent->SetupAttachment(RootComponent);

	// Points
	ResetPoints();
}

bool ABaseSeed::TargetIsEnemy(ABaseSeed* TargetSeed)
{
	if (SeedFaction != TargetSeed->SeedFaction)
	{
		return true;
	}
	return false;
}

void ABaseSeed::ResetPoints()
{
	HealthPoints = MaxHealthPoints;
}

// Called when the game starts or when spawned
void ABaseSeed::BeginPlay()
{
	Super::BeginPlay();
	if (HealthBarComponent)
	{
		if (HealthBarComponent->GetWidget() != nullptr)
		{
			HealthWidget = Cast<UHealthWidget>(HealthBarComponent->GetWidget());
		}
	}
	if (HealthWidget)
	{
		HealthWidget->HealthBar->SetPercent(GetHealthPercentage());
		if (SeedFaction == ESeedFaction::FactionEnemy)
		{
			HealthWidget->HealthBar->SetFillColorAndOpacity(HealthWidget->EnemyColour);
		}
		else
		{
			HealthWidget->HealthBar->SetFillColorAndOpacity(HealthWidget->FriendlyColour);
		}
	}
}

// Called every frame
void ABaseSeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseSeed::StartShotTimer()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ABaseSeed::ShotTimerExpired,
	                                       FireRate);
}

void ABaseSeed::FireShot()
{
	if (bCanFire == true)
	{
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + GetActorRotation().RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr && IsValid(ProjectileClass))
		{
			const auto Projectile = World->SpawnActor<AProjectSeedsProjectile>(ProjectileClass, SpawnLocation, GetActorRotation());
			Projectile->OwningActor = this;
		}

		bCanFire = false;
		StartShotTimer();

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
	HealthPoints = MaxHealthPoints;
	CheckHealth();
}

void ABaseSeed::SetHealthToZero()
{
	HealthPoints = 0.0f;
	CheckHealth();
}

void ABaseSeed::Heal(float Value)
{
	HealthPoints = FMath::Min(MaxHealthPoints, HealthPoints + Value);
	CheckHealth();
}

void ABaseSeed::CheckHealth()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("%f"), HealthPoints));
	if (HealthWidget)
	{
		HealthWidget->HealthBar->SetPercent(GetHealthPercentage());
	}
	if (HealthPoints <= 0.0f)
	{
		HandleDeath();
	}
}

void ABaseSeed::UpgradeMaxHealthPoints(float Value)
{
	MaxHealthPoints += Value;
	HealthPoints = MaxHealthPoints;
}

void ABaseSeed::HandleDeath()
{
	if (DeathRewardActor)
	{
		GetWorld()->SpawnActor<AActor>(DeathRewardActor, GetActorLocation(), GetActorRotation());
	}

	OnDeath.Broadcast(this);
	Destroy();
}

void ABaseSeed::SetMoveSpeed(float Value)
{
	this->MoveSpeed = Value;
}

float ABaseSeed::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                            AActor* DamageCauser)
{
	const float PreviousHealth = HealthPoints;
	HealthPoints -= Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	CheckHealth();

	return PreviousHealth - HealthPoints;
}
