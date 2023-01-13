// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Backrooms.h"
#include "BaseAbility.generated.h"

/**
 * 
 */
UCLASS()
class BACKROOMS_API UBaseAbility : public UGameplayAbility
{
	GENERATED_BODY()
		UBaseAbility();
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
		EBackroomsAbilityInputID AbilityInputID = EBackroomsAbilityInputID::None;
};
