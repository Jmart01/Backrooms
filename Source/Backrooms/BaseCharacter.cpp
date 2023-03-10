// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GAS = CreateDefaultSubobject<UGAS>("GASComp");
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return GAS;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		BroadCastMovement();
	}

}

void ABaseCharacter::BroadCastMovement()
{
	float currentSpeed = GetCharacterMovement()->GetLastUpdateVelocity().Size();
	if (PreviousSpeed == 0 && currentSpeed != 0)
	{
		OnMoved.Broadcast();
	}
	if (PreviousSpeed != 0 && currentSpeed == 0)
	{
		OnStoppedMoving.Broadcast();
	}
	PreviousSpeed = currentSpeed;
}


