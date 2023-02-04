// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SeedCollectable.h"
#include "SeedCollectableHealth.generated.h"

UCLASS()
class PROJECTSEEDS_API ASeedCollectableHealth : public ASeedCollectable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASeedCollectableHealth();

	UPROPERTY(EditAnywhere)
	float HealthValue = 10.0f;

	virtual void CollectAction(ASeedPlayerController* playerController, AActor* collector) override;
};
