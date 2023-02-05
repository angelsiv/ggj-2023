// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthBarComponent.h"
#include "HealthWidget.h"
#include "ProjectSeedsProjectile.h"
#include "GameFramework/Character.h"
#include "BaseSeed.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, ABaseSeed*, BaseSeed);

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

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWeaponUpgradeComponent* WeaponUpgradeComponent;
	
public:
	// Sets default values for this pawn's properties
	ABaseSeed();

	UFUNCTION(BlueprintCallable)
	bool TargetIsEnemy(ABaseSeed* TargetSeed);

	FOnDeath OnDeath;

	UPROPERTY(EditAnywhere)
	bool bCanMove = true;

	UPROPERTY(EditAnywhere)
	bool bIsAlive = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealthPoints;

	UPROPERTY(EditAnywhere)
	float MaxHealthPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UHealthBarComponent* HealthBarComponent;

	UPROPERTY(EditAnywhere)
	UHealthWidget* HealthWidget;

	UPROPERTY(EditAnywhere)
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bShouldBLine = false;
	
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AProjectSeedsProjectile> ProjectileClass;

	UFUNCTION(BlueprintCallable)
	void SetFaction(ESeedFaction Faction);

	UFUNCTION(BlueprintCallable)
	ESeedFaction GetFaction();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESeedFaction SeedFaction;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Fire a shot in the specified direction */
	UFUNCTION(BlueprintCallable)
	virtual void FireShot();

	void ResetPoints();

	// Health related stuffs
	virtual void SetHealthToFull();
	virtual void SetHealthToZero();
	virtual void Heal(float Value);
	virtual void CheckHealth();
	float GetHealthPercentage() const { return HealthPoints / MaxHealthPoints; }

	virtual void UpgradeMaxHealthPoints(float Value);

	virtual void HandleDeath();

	virtual void SetMoveSpeed(float Value);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	                         AActor* DamageCauser) override;

protected:
	void StartShotTimer();
	

private:
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;
};
