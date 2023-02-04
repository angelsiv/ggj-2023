﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerComponent.h"

#include "BaseSeed.h"


// Sets default values for this component's properties
USpawnerComponent::USpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void USpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	_spawnCountDown -= DeltaTime;

	if (_spawnCountDown <= 0.0f && _spawnedAmmount < SpawnQuantity)
	{
		_spawnCountDown = SpawningSpeed;
		_spawnedAmmount++;

		const int randomIndex = FMath::RandRange(0, Spawns.Num() - 1);
		FActorSpawnParameters spawnParameters;
		spawnParameters.Owner = GetOwner();
		spawnParameters.Instigator = Cast<ACharacter>(GetOwner());
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		if (Spawns.IsValidIndex(randomIndex))
		{
			if (const auto& ToSpawn = Spawns[randomIndex])
			{
				ABaseSeed* NewBaseSeed = Cast<ABaseSeed>(GetWorld()->SpawnActor<ABaseSeed>(ToSpawn, GetOwner()->GetActorTransform(), spawnParameters));
				NewBaseSeed->OnDeath.AddDynamic(this, &USpawnerComponent::OnSpawnDeath);
			}
		}
	}
}

void USpawnerComponent::OnSpawnDeath(ABaseSeed* BaseSeed)
{
	_spawnedAmmount--;
}