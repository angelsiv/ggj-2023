// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

#include "BaseAbility.h"

const FName UAbilityComponent::ActivateBinding("Activate");

UAbilityComponent::UAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	ActionPoints = 1;
	ResetPoints();
}

void UAbilityComponent::SetActiveAbility(ABaseAbility* Ability)
{
	SpawnedAbility = Ability->GetClass();
}

void UAbilityComponent::BindAbilities()
{
	PlayerController->InputComponent->BindAction(ActivateBinding, IE_Pressed, this, &UAbilityComponent::ActivateAbility);
}

bool UAbilityComponent::bAbilityOnCooldown()
{
	if (!GetWorld()->GetTimerManager().IsTimerActive(AbilityCooldownHandle))
	{
		return false;
	}

	return true;
}


void UAbilityComponent::ActivateAbility()
{
	if (!bActiveAbility && !bAbilityOnCooldown() && CanSpendActionPoints(1))
	{
		ABaseAbility* Projectile = GetWorld()->SpawnActor<ABaseAbility>(SpawnedAbility, Owner->GetActorLocation(), Owner->GetActorRotation());
		Projectile->OwningActor = GetOwner();

		GetWorld()->GetTimerManager().SetTimer(AbilityCooldownHandle, this, &UAbilityComponent::CooldownExpired, Projectile->AbilityCooldown, false);

		if (Projectile->AbilityDuration > 0.0f)
		{
			ActivatedAbility = Projectile;
			bActiveAbility = true;
			GetWorld()->GetTimerManager().SetTimer(ActiveDurationAbilityHandle, this, &UAbilityComponent::ActiveAbilityExpired, Projectile->AbilityDuration, false);
		}
	}
}

void UAbilityComponent::CooldownExpired()
{
	ActionPoints = FMath::Min(ActionPoints + 1, MaxActionPoints);
}

void UAbilityComponent::ActiveAbilityExpired()
{
	bActiveAbility = false;

	if (ActivatedAbility != nullptr)
	{
		ActivatedAbility->Destroy();
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

	Owner = Cast<ABaseSeed>(GetOwner());
	PlayerController = Cast<APlayerController>(Owner->GetController());

	if (IsValid(PlayerController))
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
