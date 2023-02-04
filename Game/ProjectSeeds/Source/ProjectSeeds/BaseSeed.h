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

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

public:
	// Sets default values for this pawn's properties
	ABaseSeed();

	UPROPERTY(EditAnywhere)
	bool bCanMove = true;
	UPROPERTY(EditAnywhere)
	bool bIsAlive = true;

	UPROPERTY(EditAnywhere)
	float HealtPoints;
	UPROPERTY(EditAnywhere)
	float MaxHealthPoints;

	UPROPERTY(EditAnywhere)
	int ActionPoints;
	UPROPERTY(EditAnywhere)
	int MaxActionPoints;

	UPROPERTY(EditAnywhere)
	float MoveSpeed;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> DeathRewardActor;

protected:
	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
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
	ESeedFaction SeedFaction;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Fire a shot in the specified direction */
	UFUNCTION()
	virtual void FireShot();

	void ResetPoints();

	// Health related stuffs
	virtual void SetHealthToFull();
	virtual void SetHealthToZero();
	virtual void Heal(float Value);
	virtual void CheckHealth();
	float GetHealthPercentage() const { return HealtPoints / MaxHealthPoints; }

	virtual void UpgradeMaxHealthPoints(float Value);
	virtual void UpgradeMaxActionPoints(int Value);

	// Action Points
	virtual bool CanSpendActionPoints(int Value);

	virtual void HandleDeath();

	virtual void SetMoveSpeed(float Value);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;
};
