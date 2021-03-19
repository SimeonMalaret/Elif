// Fill out your copyright notice in the Description page of Project Settings.


#include "MathUtils.h"

MathUtils::MathUtils()
{
}

MathUtils::~MathUtils()
{
}

FVector MathUtils::LinearBezier(FVector A, FVector B, float t)
{
    return (1 - t) * A + t * B;
}

FVector MathUtils::QuadraticBezier(FVector A, FVector B, FVector C, float t)
{
    return (1 - t) * LinearBezier(A, B, t) + t * LinearBezier(B, C, t);
}

FVector MathUtils::CubicBezier(FVector A, FVector B, FVector C, FVector D, float t)
{
    return (1 - t) * QuadraticBezier(A, B, C, t) + t * QuadraticBezier(B, C, D, t);
}
