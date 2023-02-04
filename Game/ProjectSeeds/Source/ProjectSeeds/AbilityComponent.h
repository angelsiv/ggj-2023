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
	
protected:
	
	void BindAbilities();
	bool bAbilityOnCooldown();
	void CooldownExpired();
	void ActivateAbility();
	void ResetPoints();

	// Action Points
	virtual bool CanSpendActionPoints(int Value);
	virtual void UpgradeMaxActionPoints(int Value);

	FTimerHandle AbilityTimerHandle;
	
	UPROPERTY(EditAnywhere)
	int MaxActionPoints;
	
	UPROPERTY(EditAnywhere)
	int ActionPoints;

	UPROPERTY()
	APlayerController* PlayerController;
	
	UPROPERTY()
	ABaseSeed* Owner;

	//Can change this to be ABaseAbility which holds cooldown & ability cost information
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABaseAbility> SpawnedAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABaseAbility* SelectedAbility;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	static const FName ActivateBinding;

	
};
