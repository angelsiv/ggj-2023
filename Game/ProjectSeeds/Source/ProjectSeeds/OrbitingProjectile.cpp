// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingProjectile.h"

#include "BaseSeed.h"
#include "Kismet/GameplayStatics.h"

AOrbitingProjectile::AOrbitingProjectile()
{
	// Set this Actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
    
	// Set default values for DistanceFromPlayer and OrbitSpeed
	OrbitSpeed = 10.0f;
	InitialLifeSpan = 0.0f;

	AbilityCooldown = 10.0f;
	AbilityCost = 1;
}

void AOrbitingProjectile::ScaleDistance(float DeltaTime)
{
	if (bIncreasing)
	{
		DistanceFromPlayer = FMath::Min(DistanceFromPlayer + DeltaTime * (MaxOrbitalDistance - MinOrbitalDistance) / 5.0f, MaxOrbitalDistance);
		if (DistanceFromPlayer >= MaxOrbitalDistance)
		{
			bIncreasing = false;
		}
	}
	else
	{
		DistanceFromPlayer = FMath::Max(DistanceFromPlayer - DeltaTime * (MaxOrbitalDistance - MinOrbitalDistance) / 5.0f, MinOrbitalDistance);
		if (DistanceFromPlayer <= MinOrbitalDistance)
		{
			bIncreasing = true;
		}
	}
}

void AOrbitingProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OrbitAround(DeltaTime);
}

void AOrbitingProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherActor != OwningActor)
	{
		ABaseSeed* Other = Cast<ABaseSeed>(OtherActor);
		if (Other != nullptr)
		{
			//probably the instigator here would be null since the bullet won't have a controller
			Other->TakeDamage(ProjectileDamage, FDamageEvent(), GetInstigatorController(), this);
		}

		if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
		}
	}
}

void AOrbitingProjectile::OrbitAround(float DeltaTime)
{
	// Get the player's location
	
	if(!IsValid(OwningActor))
	{
		return;
	}

	FVector PlayerPos;
	PlayerPos = OwningActor->GetActorLocation();
    
	// Calculate the current angle based on OrbitSpeed and DeltaTime
	float CurrentAngle = GetWorld()->GetTimeSeconds() * OrbitSpeed;

	ScaleDistance(DeltaTime);
	
	// Calculate the new position for the projectile based on the current angle
	FVector NewLocation = PlayerPos + FVector(DistanceFromPlayer * FMath::Cos(CurrentAngle), DistanceFromPlayer * FMath::Sin(CurrentAngle), 0.0f);
    
	// Set the new location for the projectile
	SetActorLocation(NewLocation);
}
