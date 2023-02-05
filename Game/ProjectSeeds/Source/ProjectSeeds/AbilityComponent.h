// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAbility.h"
#include "BaseSeed.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTSEEDS_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

	void SetActiveAbility(ABaseAbility* Ability);
	
	// Action Points
	virtual bool CanSpendActionPoints(int Value);
	virtual void UpgradeMaxActionPoints(int Value);
	void ResetPoints();
	
	UPROPERTY(EditAnywhere)
	int MaxActionPoints;
	
	UPROPERTY(EditAnywhere)
	int ActionPoints;
	
protected:
	void BindAbilities();
	bool bAbilityOnCooldown();
	void CooldownExpired();
	void ActiveAbilityExpired();
	void ActivateAbility();

	FTimerHandle ActiveDurationAbilityHandle;
	FTimerHandle AbilityCooldownHandle;

	bool bActiveAbility;
	
	UPROPERTY()
	APlayerController* PlayerController;
	
	UPROPERTY()
	ABaseSeed* Owner;

	//Can change this to be ABaseAbility which holds cooldown & ability cost information
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABaseAbility> SpawnedAbility;

	UPROPERTY()
	AProjectSeedsProjectile* ActivatedAbility;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	static const FName ActivateBinding;
};
