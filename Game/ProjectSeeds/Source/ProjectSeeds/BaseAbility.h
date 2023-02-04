// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectSeedsProjectile.h"
#include "GameFramework/Actor.h"
#include "BaseAbility.generated.h"


UCLASS()
class PROJECTSEEDS_API ABaseAbility : public AProjectSeedsProjectile
{
	//Meant to be spawned in the world
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AbilityCost;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AbilityCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AbilityDuration;
	
	
protected:

};
