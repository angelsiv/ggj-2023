// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

const FName UAbilityComponent::ActivateBinding("Activate");

UAbilityComponent::UAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	ActionPoints = 1;

}

void UAbilityComponent::BindAbilities()
{
	PlayerController->InputComponent->BindAction(ActivateBinding, IE_Pressed, this, &UAbilityComponent::ActivateAbility);

}

void UAbilityComponent::ActivateAbility()
{
	if(CanSpendActionPoints(1))
	{
		//SelectedAbility->FireAbility();
		AProjectSeedsProjectile* Projectile = GetWorld()->SpawnActor<AProjectSeedsProjectile>(SelectedAbility, Owner->GetActorLocation(), Owner->GetActorRotation());
		Projectile->OwningActor = GetOwner();
	}
}

void UAbilityComponent::ResetPoints()
{
	ActionPoints = MaxActionPoints;
}

void UAbilityComponent::UpgradeMaxActionPoints(int Value)
{
	MaxActionPoints += Value;
	ActionPoints = MaxActionPoints;
}

bool UAbilityComponent::CanSpendActionPoints(int Value)
{
	if (ActionPoints >= Value)
	{
		ActionPoints -= Value;
		return true;
	}

	return false;
}
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Owner			 = Cast<ABaseSeed>(GetOwner());
	PlayerController = Cast<APlayerController>(Owner->GetController());

	if(IsValid(PlayerController))
	{
		BindAbilities();
	}
}


// Called every frame
void UAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

