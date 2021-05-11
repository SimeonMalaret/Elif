// Copyright Epic Games, Inc. All Rights Reserved.

#include "DreamHuntersGameMode.h"
#include "DreamHuntersCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADreamHuntersGameMode::ADreamHuntersGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/SecondGameplayCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
