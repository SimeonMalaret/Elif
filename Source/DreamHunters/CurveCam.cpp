// Fill out your copyright notice in the Description page of Project Settings.


#include "CurveCam.h"
#include "MathUtils.h"

CurveCam::CurveCam()
{
}

CurveCam::~CurveCam()
{
}

FVector CurveCam::GetPosition(float t) 
{
	return MathUtils::CubicBezier(A, B, C, D, t);
}

FVector CurveCam::GetPositionMat(float t, FMatrix localToWorldMatrix) 
{
	return localToWorldMatrix.TransformVector(GetPosition(t));
}
