// Fill out your copyright notice in the Description page of Project Settings.


#include "AView.h"
#include "CameraManager.h"
#include "CameraConfig.h"
#include "LevelDesign_GameMode.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

// Sets default values for this component's properties
UAView::UAView()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

CameraConfig* UAView::GetConfiguration() {
	return cameraConfig;
}

// Called when the game starts
void UAView::BeginPlay()
{
	Super::BeginPlay();
	// ...
	cameraConfig = new CameraConfig();
}


// Called every frame
void UAView::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAView::SetActiveView(bool IsActive) {
	ALevelDesign_GameMode* levelDesignGM = (ALevelDesign_GameMode*)GetWorld()->GetAuthGameMode();

	if (IsActive)
	{
		levelDesignGM->CameraManager->views.Add(this);
	}
	else
	{
		levelDesignGM->CameraManager->views.Remove(this);
	}
}


