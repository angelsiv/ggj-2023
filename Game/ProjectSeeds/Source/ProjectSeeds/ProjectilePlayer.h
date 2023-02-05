// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectSeedsProjectile.h"
#include "ProjectilePlayer.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSEEDS_API AProjectilePlayer : public AProjectSeedsProjectile
{
	GENERATED_BODY()
	AProjectilePlayer();

	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
