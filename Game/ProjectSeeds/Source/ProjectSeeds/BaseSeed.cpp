// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeed.h"

#include "ProjectSeedsProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseSeed::ABaseSeed()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	ShipMeshComponent->SetupAttachment(RootComponent);
	//RootComponent = CapsuleComponent;
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;
	
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.2f;
	bCanFire = true;
}	

// Called when the game starts or when spawned
void ABaseSeed::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseSeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseSeed::FireShot()
{
	if (bCanFire == true)
	{
		// Spawn projectile at an offset from this pawn
		const FVector SpawnLocation = GetActorLocation() + GetActorRotation().RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// spawn the projectile
			World->SpawnActor<AProjectSeedsProjectile>(SpawnLocation, GetActorRotation());
		}

		bCanFire = false;
		World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ABaseSeed::ShotTimerExpired,
										  FireRate);

		// try and play the sound if specified
		if (FireSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		bCanFire = false;
	}
}

void ABaseSeed::ShotTimerExpired()
{
	bCanFire = true;
}

// // Called to bind functionality to input
// void ABaseSeed::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
// }

void ABaseSeed::SetHealthToFull()
{
	this->Health = 1;
}

void ABaseSeed::SetHealthToZero()
{
	this->Health = 0;
}

void ABaseSeed::Heal(float Value)
{
}

void ABaseSeed::Damage(ABaseSeed Target, float Value)
{
	
}

void ABaseSeed::SetMoveSpeed(float Value)
{
	this->MoveSpeed = Value;
}



