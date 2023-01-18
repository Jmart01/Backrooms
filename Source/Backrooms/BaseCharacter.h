// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <GameplayEffectTypes.h>
#include "GAS.h"
#include "BaseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMovedDelegate);

UCLASS()
class BACKROOMS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UGAS* GAS;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FOnMovedDelegate OnMoved;
	FOnMovedDelegate OnStoppedMoving;
	void BroadCastMovement();

private:
	float PreviousSpeed = 0.f;

	
};
