// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSeed.h"
#include "GameFramework/Pawn.h"
#include "BaseSeedAI.generated.h"

UCLASS()
class PROJECTSEEDS_API ABaseSeedAI : public ABaseSeed
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseSeedAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void FireShot() override;

	//EFighterType Type;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
