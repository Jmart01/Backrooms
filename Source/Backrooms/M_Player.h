// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "BaseAbility.h"
#include "InputActionValue.h"
#include "M_Player.generated.h"

/**
 * 
 */
class UInputComponent;
class UInputMappingContext;
UCLASS()
class BACKROOMS_API AM_Player : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AM_Player();


protected:
	virtual void BeginPlay();

	//******************Inputs************************************//

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* LookAction;
	
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);
	//*****************Ability System******************************//
	UPROPERTY()
	class UActorAttributesSet* Attributes;
	virtual void InitializeAttributes();
	virtual void GiveAbilities();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
		TArray<TSubclassOf<class UBaseAbility>> DefaultAbilities;
	
	//*******************Components********************************//

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* PlayerEye;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* TP_Mesh;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	
};
