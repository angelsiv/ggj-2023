// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeedCollectable.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSeedCollectable, All, All);

class ASeedPlayerController;

UCLASS()
class PROJECTSEEDS_API ASeedCollectable : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASeedCollectable();
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneRootComponent;
	
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(Category = Collision, VisibleAnywhere)
	class USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere)
	int CurrentValue = 1;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 3.0f;
	UPROPERTY(EditAnywhere)
	float WobbleSpeed = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	USoundBase* PickupSound;

	void Collect(ASeedPlayerController* playerController, AActor* collector);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
};
