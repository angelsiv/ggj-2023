// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SeedStation.h"
#include "ActionSeedStation.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API AActionSeedStation : public ASeedStation
{
	GENERATED_BODY()

public:
	virtual void StationAction() override;
};
