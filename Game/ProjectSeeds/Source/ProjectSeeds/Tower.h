// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSeedAI.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API ATower : public ABaseSeedAI
{
	GENERATED_BODY()

	ATower();

	// Sphere collider used for range
	UPROPERTY(Category = Collision, EditAnywhere)
	class USphereComponent* SphereComponent;

public:
	UPROPERTY(Category = Gameplay, EditAnywhere)
	class ABaseSeed* Target;

public:
	UFUNCTION()
	void ChangeFaction();

	virtual void FireShot() override;
	
	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp,
	                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void PostInitializeComponents() override;

private:
	UPROPERTY()
	float RangeRadius = 10.0f;
};
