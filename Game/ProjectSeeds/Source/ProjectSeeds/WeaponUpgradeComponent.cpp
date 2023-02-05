// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponUpgradeComponent.h"

// Sets default values for this component's properties
UWeaponUpgradeComponent::UWeaponUpgradeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

int UWeaponUpgradeComponent::GetNumBullets()
{
	return NumExtraBullets;
}

void UWeaponUpgradeComponent::PurchaseWeaponUpgrade()
{
	NumExtraBullets++;
}

// Called every frame
void UWeaponUpgradeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

