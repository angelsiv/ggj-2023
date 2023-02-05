// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionSeedStation.h"

#include "AbilityComponent.h"
#include "ProjectSeedsPawn.h"
#include "SeedPlayerController.h"

AActionSeedStation::AActionSeedStation()
{
	CurrencyCost = 30.0f;
}

void AActionSeedStation::StationAction()
{
	Super::StationAction();
	
	if (auto* seedPC = ASeedPlayerController::GetInstance(this))
	{
		if (const auto* seedPawn = seedPC->GetSeedPawn())
		{
			if (auto* WeaponUpgrade = Cast<UAbilityComponent>(seedPawn->GetComponentByClass(UAbilityComponent::StaticClass())))
			{
				if (seedPC->CanSpendCurrency(CurrencyCost))
				{
					WeaponUpgrade->UpgradeMaxActionPoints(static_cast<int>(UpgradeAmount));
				}
			}
		}
	}
}
