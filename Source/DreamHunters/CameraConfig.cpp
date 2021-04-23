// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraConfig.h"

CameraConfig::CameraConfig()
{

	yaw = 0;
	pitch = 0;
	roll = 0;

	pivot = FVector::ZeroVector;

	distance = 0;
	fov = 0;
}

CameraConfig::~CameraConfig()
{
}

FQuat CameraConfig::GetRotation() {
	FVector EulerVector;
	EulerVector.X = pitch;
	EulerVector.Y = yaw;
	EulerVector.Z = roll;

	return FQuat::MakeFromEuler(EulerVector);
}

FVector CameraConfig::GetPosition() {
	FVector offset = GetRotation() * (FVector::BackwardVector * distance);
	return pivot + offset;
}
