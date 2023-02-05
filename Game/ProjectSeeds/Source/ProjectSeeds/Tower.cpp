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
	
	if(Distance <= RangeRadius)
	{
		return true;
	}
	else return false;
}
