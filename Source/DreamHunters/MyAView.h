// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AView.h"
#include "Rail.h"
#include "MyAView.generated.h"

/**
 * 
 */
UCLASS()
class DREAMHUNTERS_API UMyAView : public UAView
{
	GENERATED_BODY()

public:

	UMyAView();

	UPROPERTY(EditAnywhere, meta = (ClampMin = "-180", ClampMax = "180", UIMin = "-180", UIMax = "180"))
	float roll;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "1", ClampMax = "179", UIMin = "1", UIMax = "179"))
	float fov;

	float distance;

	UPROPERTY(EditAnywhere)
	AActor* target;

	UPROPERTY(EditAnywhere)
	ARail* rail;

	UPROPERTY(EditAnywhere)
	float speed;

	virtual void BeginPlay() override;

	virtual CameraConfig* GetConfiguration() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:

	float railPosition;
};
