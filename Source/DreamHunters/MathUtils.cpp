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

FMatrix MathUtils::GetTranslationMatrix(FVector position) 
{
    return FMatrix(FPlane(1, 0, 0, 0), FPlane(0, 1, 0, 0), FPlane(0, 0, 1, 0), FPlane(position.X, position.Y, position.Z, 1));
}

FMatrix MathUtils::GetRotationMatrix(FQuat anglesDeg)
{
    anglesDeg = FQuat(FMath::DegreesToRadians(anglesDeg.X), FMath::DegreesToRadians(anglesDeg.Y), FMath::DegreesToRadians(anglesDeg.Z), FMath::DegreesToRadians(anglesDeg.W));

    FMatrix rotationX = FMatrix(FPlane(1, 0, 0, 0),
        FPlane(0, FMath::Cos(anglesDeg.X), FMath::Sin(anglesDeg.X), 0),
        FPlane(0, -FMath::Sin(anglesDeg.X), FMath::Cos(anglesDeg.X), 0),
        FPlane(0, 0, 0, 1));

    FMatrix rotationY = FMatrix(FPlane(FMath::Cos(anglesDeg.Y), 0, -FMath::Sin(anglesDeg.Y), 0),
        FPlane(0, 1, 0, 0),
        FPlane(FMath::Sin(anglesDeg.Y), 0, FMath::Cos(anglesDeg.Y), 0),
        FPlane(0, 0, 0, 1));

    FMatrix rotationZ = FMatrix( FPlane(FMath::Cos(anglesDeg.Z), FMath::Sin(anglesDeg.Z), 0, 0),
        FPlane(-FMath::Sin(anglesDeg.Z), FMath::Cos(anglesDeg.Z), 0, 0),
        FPlane(0, 0, 1, 0),
        FPlane(0, 0, 0, 1));

    return rotationX * rotationY * rotationZ;
}

FMatrix MathUtils::GetScaleMatrix(FVector scale)
{
    return FMatrix(FPlane(scale.X, 0, 0, 0), FPlane(0, scale.Y, 0, 0), FPlane(0, 0, scale.Z, 0), FPlane(0, 0, 0, 1));
}

FMatrix MathUtils::TRSMatrix(FVector position, FQuat anglesDeg, FVector scale)
{
    return GetTranslationMatrix(position) * FRotationMatrix::Make(anglesDeg) * GetScaleMatrix(scale);
}
