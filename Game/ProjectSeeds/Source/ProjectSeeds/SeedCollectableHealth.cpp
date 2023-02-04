// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedCollectableHealth.h"
#include "ProjectSeedsPawn.h"
#include "SeedPlayerController.h"


// Sets default values
ASeedCollectableHealth::ASeedCollectableHealth()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ASeedCollectableHealth::CollectAction(ASeedPlayerController* playerController, AActor* collector)
{
	if (IsValid(playerController))
	{
		if (auto* seedPawn = playerController->GetSeedPawn())
		{
			seedPawn->Heal(HealthValue);
		}
	}
	
	Super::CollectAction(playerController, collector);
}
