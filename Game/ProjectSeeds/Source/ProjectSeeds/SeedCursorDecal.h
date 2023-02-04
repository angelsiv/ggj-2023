// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeedCursorDecal.generated.h"

UCLASS()
class PROJECTSEEDS_API ASeedCursorDecal : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASeedCursorDecal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	FVector DecalSize = FVector(16.0f, 32.0f, 32.0f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
