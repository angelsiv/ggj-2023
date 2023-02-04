// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeedAI.h"

#include "ProjectSeedsProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseSeedAI::ABaseSeedAI()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SeedFaction = ESeedFaction::FactionEnemy;
}

// Called when the game starts or when spawned
void ABaseSeedAI::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseSeedAI::FireShot()
{
	if (bCanFire == true)
	{
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + GetActorRotation().RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile, with randomness for fairness vs player
			float RandomAngle = FMath::RandRange(-35, 35);
			FRotator Randomness = FRotator(0, RandomAngle, 0);
			const auto Projectile = World->SpawnActor<AProjectSeedsProjectile>(ProjectileClass, SpawnLocation, GetActorRotation() + Randomness);
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

// Called every frame
void ABaseSeedAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
