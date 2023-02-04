// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "SpawnerComponent.h"
#include "Components/SphereComponent.h"

ATower::ATower()
{
	bCanMove = false;
	bCanFire = true;
	SeedFaction = ESeedFaction::FactionEnemy;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->InitSphereRadius(RangeRadius);

	SpawnerComponent = CreateDefaultSubobject<USpawnerComponent>(TEXT("SpawnerComponent"));
}

void ATower::ChangeFaction()
{
	(SeedFaction == ESeedFaction::FactionEnemy)
		? SeedFaction = ESeedFaction::FactionPlayer
		: SeedFaction = ESeedFaction::FactionEnemy;
}

void ATower::FireShot()
{
	if (Target != nullptr)
	{
		// Shoot at target
		// Need some bullet pool...
	}
}

void ATower::OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp,
                                int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)

{
	if(auto* Entity = Cast<ABaseSeedAI>(Other))
	{
		if (Entity->SeedFaction != SeedFaction) // Verify target is of different faction
		{
			Target = Entity;
			FireShot();
		}
	};
}

void ATower::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ATower::OnComponentOverlap);
}
