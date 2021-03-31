// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AView.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DREAMHUNTERS_API UAView : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAView();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	class CameraConfig* cameraConfig;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "1.0", UIMin = "0", UIMax = "1.0"))
	float weight;

	virtual CameraConfig* GetConfiguration();

	virtual void SetActiveView(bool isActive);
};
