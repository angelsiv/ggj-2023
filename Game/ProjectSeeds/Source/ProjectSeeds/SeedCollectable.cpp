// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedCollectable.h"

#include "SeedPlayerController.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogSeedCollectable);

// Sets default values
ASeedCollectable::ASeedCollectable()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneRootComponent;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetCollisionProfileName("SeedCollectable");
	StaticMeshComponent->SetupAttachment(RootComponent);
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereComponent->SetupAttachment(RootComponent);
}

void ASeedCollectable::Collect(ASeedPlayerController* playerController, AActor* collector)
{
	CollectAction(playerController,collector);

	// Play Pickup sound
	if (PickupSound)
	{
		UGameplayStatics::PlaySound2D(this, PickupSound);
	}
	
	Destroy();
}

void ASeedCollectable::CollectAction(ASeedPlayerController* playerController, AActor* collector)
{
	if (IsValid(playerController))
	{
		UE_LOG(LogSeedCollectable, Display, TEXT("%s Pickup %s"), *GetNameSafe(collector), *GetName());
		playerController->IncreaseCurrency(CurrentValue);
	}
}

// Called every frame
void ASeedCollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->AddActorWorldRotation(
		FRotator(
			0.0f,															 // Pitch
			RotationSpeed,													 // Yaw
			WobbleSpeed * sinf(UGameplayStatics::GetTimeSeconds(GetWorld()) + GetUniqueID()) // Roll
		));
}


