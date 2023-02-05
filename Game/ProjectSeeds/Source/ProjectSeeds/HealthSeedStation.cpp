// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthSeedStation.h"

#include "ProjectSeedsPawn.h"
#include "SeedPlayerController.h"

AHealthSeedStation::AHealthSeedStation()
{
	CurrencyCost = 10.0f;
	UpgradeAmount = 50.0f;
}

void AHealthSeedStation::StationAction()
{
	Super::StationAction();

	if (auto* seedPC = ASeedPlayerController::GetInstance(this))
	{
		if (auto* seedPawn = seedPC->GetSeedPawn())
		{
			if (seedPC->CanSpendCurrency(CurrencyCost))
			{
				seedPawn->UpgradeMaxHealthPoints(UpgradeAmount);
			}
		}
	}
}
