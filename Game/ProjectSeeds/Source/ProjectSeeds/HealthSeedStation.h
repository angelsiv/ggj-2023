// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SeedStation.h"
#include "HealthSeedStation.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API AHealthSeedStation : public ASeedStation
{
	GENERATED_BODY()
	AHealthSeedStation();
public:
	virtual void StationAction() override;
};
