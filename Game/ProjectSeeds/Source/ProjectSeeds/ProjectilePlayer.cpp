// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectilePlayer.h"

AProjectilePlayer::AProjectilePlayer()
{
	ProjectileMesh->BodyInstance.SetCollisionProfileName("ProjectilePlayer");
}

void AProjectilePlayer::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
}
