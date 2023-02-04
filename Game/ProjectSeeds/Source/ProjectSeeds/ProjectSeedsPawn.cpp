// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectSeedsPawn.h"
#include "ProjectSeedsProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AProjectSeedsPawn::MoveForwardBinding("MoveForward");
const FName AProjectSeedsPawn::MoveRightBinding("MoveRight");
const FName AProjectSeedsPawn::FireForwardBinding("FireForward");
const FName AProjectSeedsPawn::FireRightBinding("FireRight");
const FName AProjectSeedsPawn::FireBinding("Fire");

AProjectSeedsPawn::AProjectSeedsPawn()
{	
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	SeedFaction = ESeedFaction::FactionPlayer;
}

void AProjectSeedsPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	
	PlayerInputComponent->BindAction(FireBinding, IE_Pressed, this, &AProjectSeedsPawn::SetFiringPressed);
	PlayerInputComponent->BindAction(FireBinding, IE_Released, this, &AProjectSeedsPawn::SetFiringReleased);
}

void AProjectSeedsPawn::SetFiringPressed()
{
	bIsFiringPressed = true;	
}

void AProjectSeedsPawn::SetFiringReleased()
{
	bIsFiringPressed = false;
}

bool AProjectSeedsPawn::IsFireInputPressed()
{
	if(!bIsFiringPressed)
	{
		return false;
	}
	
	return true;
}


void AProjectSeedsPawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
	
	RotateTowardsMouse();

	if(IsFireInputPressed())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("input pressed")));
		FireShot();	
	}
}

void AProjectSeedsPawn::RotateTowardsMouse()
{
	FVector MouseLocation;
	FVector MouseDirection;
	PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);

	FRotator Rotation = FRotationMatrix::MakeFromX(MouseDirection).Rotator();
	SetActorRotation(FRotator(0, Rotation.Yaw, 0));
}

void AProjectSeedsPawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetShowMouseCursor(true);
	
}

