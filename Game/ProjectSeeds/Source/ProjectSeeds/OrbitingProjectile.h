// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "ProjectSeedsProjectile.h"
#include "OrbitingProjectile.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API AOrbitingProjectile : public AProjectSeedsProjectile
{
	GENERATED_BODY()

public:
	AOrbitingProjectile();

	//virtual void FireAbility() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	// Distance between the player and the projectile
	UPROPERTY(EditAnywhere)
	float DistanceFromPlayer;
    
	// Speed at which the projectile orbits the player
	UPROPERTY(EditAnywhere)
	float OrbitSpeed;

protected:
	void OrbitAround();
};
