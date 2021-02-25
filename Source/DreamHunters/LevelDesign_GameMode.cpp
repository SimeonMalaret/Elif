// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelDesign_GameMode.h"
#include "DreamHuntersCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALevelDesign_GameMode::ALevelDesign_GameMode()
{
	static ConstructorHelpers::FClassFinder<APawn>LevelDesignPawnBP(TEXT("/Game/ThirdPersonCPP/Blueprints/SecondGameplayCharacter"));
	if (LevelDesignPawnBP.Class != NULL)
	{
		DefaultPawnClass = LevelDesignPawnBP.Class;
	}
}

