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

	// Sphere collider used for range
	UPROPERTY(Category = Collision, VisibleAnywhere)
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere)
	USpawnerComponent* SpawnerComponent;

public:
	UPROPERTY(Category = Gameplay, EditAnywhere)
	ABaseSeed* Target;

public:
	UFUNCTION()
	void ChangeFaction();

	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp,
							int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void PostInitializeComponents() override;

private:
	UPROPERTY()
	float RangeRadius = 10.0f;
};
