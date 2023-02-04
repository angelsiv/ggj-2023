// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "SpawnerComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
	bCanMove = false;
	bCanFire = true;
	SeedFaction = ESeedFaction::FactionEnemy;

	SpawnerComponent = CreateDefaultSubobject<USpawnerComponent>(TEXT("SpawnerComponent"));
}

void ATower::ChangeFaction()
{
	(SeedFaction == ESeedFaction::FactionEnemy)
		? SeedFaction = ESeedFaction::FactionPlayer
		: SeedFaction = ESeedFaction::FactionEnemy;
}



bool ATower::bIsInRange(ABaseSeed* Entity)
{
	const auto Distance = FVector::Dist(GetActorLocation(), Entity->GetActorLocation());
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("%f"), Distance));
	
	if(Distance <= RangeRadius)
	{
		return true;
	}
	else return false;
}

void ATower::FireShot()
{
	if (bCanFire == true)
	{
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + GetActorRotation().RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
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
