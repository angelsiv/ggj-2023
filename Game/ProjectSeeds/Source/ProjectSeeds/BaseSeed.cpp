// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeed.h"

#include "AbilityComponent.h"
#include "ProjectSeedsProjectile.h"
#include "WeaponUpgradeComponent.h"
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

	AbilityComponent       = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbiilityComponent"));
	WeaponUpgradeComponent = CreateDefaultSubobject<UWeaponUpgradeComponent>(TEXT("WeaponUpgradeComponent"));

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
	HealthBarComponent->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);

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
	CheckHealth();
	AbilityComponent->ResetPoints();
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
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = GetOwner();
			SpawnParam.Instigator = Cast<ACharacter>(GetOwner());
			SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			
			const auto Projectile = World->SpawnActor<AProjectSeedsProjectile>(ProjectileClass, SpawnLocation, GetActorRotation(), SpawnParam);
			Projectile->OwningActor = this;
			
			
			if(WeaponUpgradeComponent->GetNumBullets() > 0)
			{
				for(int i = 0; i < WeaponUpgradeComponent->GetNumBullets(); i++)
				{
					float RandomAngleLeft = FMath::RandRange(-15, 5);
					float RandomAngleRight = FMath::RandRange(5, 15);

					int Random = FMath::RandRange(0,1);
					FRotator RandomAngle;

					switch(Random)
					{
						case 0:
							RandomAngle =  FRotator(0, RandomAngleLeft, 0);
							break;
						case 1:
							RandomAngle = FRotator(0, RandomAngleRight, 0);
							break;
						default:
							break;
					}

					
					const auto ExtraProjectile = World->SpawnActor<AProjectSeedsProjectile>(ProjectileClass,
						SpawnLocation,
						GetActorRotation() + RandomAngle,
						SpawnParam);
					
					ExtraProjectile->OwningActor = this;

				}
			}
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

void ABaseSeed::SetFaction(ESeedFaction Faction)
{
	SeedFaction = Faction;
}

ESeedFaction ABaseSeed::GetFaction()
{
	return SeedFaction;
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
	OnCheckHealthPoints.Broadcast(HealthPoints, MaxHealthPoints);
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
	CheckHealth();
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
