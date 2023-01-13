// Copyright Epic Games, Inc. All Rights Reserved.

#include "BackroomsGameMode.h"
#include "BackroomsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABackroomsGameMode::ABackroomsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
