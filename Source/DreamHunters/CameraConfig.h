// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DREAMHUNTERS_API CameraConfig
{
public:
	CameraConfig();
	~CameraConfig();

	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (ClampMin = "0", ClampMax = "360.0", UIMin = "0", UIMax = "360.0"))
	float yaw;
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (ClampMin = "-90.0", ClampMax = "90.0", UIMin = "-90.0", UIMax = "90.0"))
	float pitch;
	UPROPERTY(EditAnywhere, Category = "Rotation", meta = (ClampMin = "0", ClampMax = "360.0", UIMin = "0", UIMax = "360.0"))
	float roll;

	FVector pivot;

	float distance;
	UPROPERTY(EditAnywhere, meta = (ClampMin = "1.0", ClampMax = "179.0", UIMin = "1.0", UIMax = "179.0"))
	float fov;

	FQuat GetRotation();
	FVector GetPosition();
};
