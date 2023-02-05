// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSeedStation.h"

#include "ProjectSeedsPawn.h"
#include "SeedPlayerController.h"
#include "WeaponUpgradeComponent.h"

void AWeaponSeedStation::StationAction()
{
	if (auto* seedPC = ASeedPlayerController::GetInstance(this))
	{
		if (const auto* seedPawn = seedPC->GetSeedPawn())
		{
			if (auto* WeaponUpgrade = Cast<UWeaponUpgradeComponent>(seedPawn->GetComponentByClass(UWeaponUpgradeComponent::StaticClass())))
			{
				if (seedPC->CanSpendCurrency(CurrencyCost))
				{
					WeaponUpgrade->PurchaseWeaponUpgrade(static_cast<int>(UpgradeAmount));
				}
			}
		}
	}
	
	Super::StationAction();
}
