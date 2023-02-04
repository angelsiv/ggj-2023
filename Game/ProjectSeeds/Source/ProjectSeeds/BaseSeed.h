// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseSeed.generated.h"

UENUM()
enum class ESeedFaction : uint8
{
	FactionPlayer,
	FactionEnemy
};

UCLASS()
class PROJECTSEEDS_API ABaseSeed : public ACharacter
{
	GENERATED_BODY()

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;
	
public:
	// Sets default values for this pawn's properties
	ABaseSeed();

	UPROPERTY(EditAnywhere) bool bCanMove = true;
	UPROPERTY(EditAnywhere) bool bIsAlive = true;
	UPROPERTY(EditAnywhere) float Health;
	UPROPERTY(EditAnywhere) float MoveSpeed;

protected:
	/* Flag to control firing  */
	uint32 bCanFire : 1;
	
	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite )
	FVector GunOffset;
	
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Fire a shot in the specified direction */
	UFUNCTION()
	virtual void FireShot();
	
	// Health related stuffs
	virtual void SetHealthToFull();
	virtual void SetHealthToZero();
	virtual void Heal(float Value);
	virtual void Damage(ABaseSeed Target, float Value);
	
	virtual void SetMoveSpeed(float Value);

	ESeedFaction SeedFaction;

private:
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
};
