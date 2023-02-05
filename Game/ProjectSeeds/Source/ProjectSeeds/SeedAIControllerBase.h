// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseSeed.h"
#include "SeedAIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API ASeedAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void BLine(bool bShouldBLine);
};
