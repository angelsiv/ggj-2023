// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectSeedsProjectile.h"
#include "GameFramework/Actor.h"
#include "BaseAbility.generated.h"

UCLASS()
class PROJECTSEEDS_API ABaseAbility : public AProjectSeedsProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseAbility();

	virtual void FireAbility();
protected:
	
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

};
