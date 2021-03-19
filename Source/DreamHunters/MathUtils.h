// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
static class DREAMHUNTERS_API MathUtils
{
public:
	MathUtils();
	~MathUtils();

    static FVector LinearBezier(FVector A, FVector B, float t);

    static FVector QuadraticBezier(FVector A, FVector B, FVector C, float t);

    static FVector CubicBezier(FVector A, FVector B, FVector C, FVector D, float t);

};
