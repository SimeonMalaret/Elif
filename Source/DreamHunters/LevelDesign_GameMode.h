// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraManagerActor.h"
#include "LevelDesign_GameMode.generated.h"

/**
 * 
 */
UCLASS(minimalapi)
class ALevelDesign_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ALevelDesign_GameMode();

	//void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	ACameraManagerActor* CameraManager;
};
