// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SeedStation.h"
#include "WeaponSeedStation.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API AWeaponSeedStation : public ASeedStation
{
	GENERATED_BODY()
	
public:
	virtual void StationAction() override;
};
