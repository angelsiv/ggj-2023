// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseSeed.generated.h"

UENUM()
enum class ESeedFaction : uint8
{
	FactionPlayer,
	FactionEnemy
};

UCLASS()
class PROJECTSEEDS_API ABaseSeed : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseSeed();

	UPROPERTY(EditAnywhere) bool bCanMove = true;
	UPROPERTY(EditAnywhere) bool bIsAlive = true;
	UPROPERTY(EditAnywhere) float Health;
	UPROPERTY(EditAnywhere) float MoveSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Health related stuffs
	virtual void SetHealthToFull();
	virtual void SetHealthToZero();
	virtual void Heal(float Value);
	virtual void Damage(ABaseSeed Target, float Value);
	
	virtual void SetMoveSpeed(float Value);

	ESeedFaction SeedFaction;
};
