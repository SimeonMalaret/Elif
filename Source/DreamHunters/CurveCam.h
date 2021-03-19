// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DREAMHUNTERS_API CurveCam
{
public:
	CurveCam();
	~CurveCam();

	FVector A;
	FVector B;
	FVector C;
	FVector D;

	FVector GetPosition(float t);

	FVector GetPositionMat(float t, FMatrix localToWorldMatrix);
};
