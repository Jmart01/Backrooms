// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ActorAttributesSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
		 GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class BACKROOMS_API UActorAttributesSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UActorAttributesSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Sanity;
	ATTRIBUTE_ACCESSORS(UActorAttributesSet, Sanity)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxSanity;
	ATTRIBUTE_ACCESSORS(UActorAttributesSet, MaxSanity)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UActorAttributesSet, Stamina)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UActorAttributesSet, MaxStamina)
};
