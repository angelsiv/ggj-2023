// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "OrbitingProjectile.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API AOrbitingProjectile : public ABaseAbility
{
	GENERATED_BODY()

public:
	AOrbitingProjectile();
	void ScaleDistance(float DeltaTime);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	float DistanceFromPlayer;
    
	// Speed at which the projectile orbits the player
	UPROPERTY(EditAnywhere)
	float OrbitSpeed;

protected:
	float MaxOrbitalDistance = 500.0f;
	float MinOrbitalDistance = 200.0f;

	
	bool bIncreasing = false;

	void OrbitAround(float DeltaTime);
};
