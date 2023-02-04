// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSeedAI.h"
#include "Tower.generated.h"

class USpawnerComponent;
/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API ATower : public ABaseSeedAI
{
	GENERATED_BODY()

	ATower();

	UPROPERTY(VisibleAnywhere)
	USpawnerComponent* SpawnerComponent;

public:
	UPROPERTY(Category = Gameplay, EditAnywhere)
	ABaseSeed* Target;

public:
	UFUNCTION()
	void ChangeFaction();

	UFUNCTION(BlueprintCallable)
	bool bIsInRange(ABaseSeed* Entity);

protected:
	virtual void FireShot() override;

private:
	UPROPERTY()
	float RangeRadius = 2000.0f;
};
