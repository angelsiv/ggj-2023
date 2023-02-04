// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnerComponent.generated.h"

class ABaseSeed;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTSEEDS_API USpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USpawnerComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<ABaseSeed>> Spawns;
	UPROPERTY(EditAnywhere)
	float SpawningSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
	int SpawnQuantity = 5;

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float _spawnCountDown = 0.0f;
	int _spawnedAmmount = 0;

	UFUNCTION()
	void OnSpawnDeath(ABaseSeed* BaseSeed);
};
