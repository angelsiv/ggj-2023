﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeedStation.generated.h"

class UWidgetComponent;

UCLASS()
class PROJECTSEEDS_API ASeedStation : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASeedStation();

	virtual void PostInitializeComponents() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class USceneComponent* SceneRootComponent;

	/* The mesh component */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWidgetComponent* WidgetComponent;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	float DelayUpgradeTime = 2.0f;

	UPROPERTY(EditAnywhere)
	int CurrencyCost = 1;

	UPROPERTY(EditAnywhere)
	float UpgradeAmount = 1.0f;

	UPROPERTY(EditAnywhere)
	FString Text = TEXT("Station Type");

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual bool CanStationAction();
	virtual void StationAction();

protected:
	FTimerHandle TimerHandle;
};