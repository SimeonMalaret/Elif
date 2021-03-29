// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AView.h"
#include "Curve.h"
#include "CameraConfig.h"
#include "DreamHuntersCharacter.h"
#include "FreeFollowView.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DREAMHUNTERS_API UFreeFollowView : public UAView
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float pitch[3];
	UPROPERTY(EditAnywhere)
	float roll[3];
	UPROPERTY(EditAnywhere)
	float fov[3];

	UPROPERTY(EditAnywhere)
	float yaw;
	UPROPERTY(EditAnywhere)
	float yawSpeed;

	UPROPERTY(EditAnywhere)
	ADreamHuntersCharacter* player;
	UPROPERTY(EditAnywhere)
	UCurve* curve;
	UPROPERTY(EditAnywhere)
	float curvePosition;
	UPROPERTY(EditAnywhere)
	float curveSpeed;
	
	virtual CameraConfig* GetConfiguration() override;
	virtual void SetActiveView(bool isActive) override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private :
	float fieldOfView;
	float _roll;
	float _pitch;
	FVector positionCamera;

	FMatrix matrix;

	float Lerp(float list[], float position);
};
