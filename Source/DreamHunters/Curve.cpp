// Fill out your copyright notice in the Description page of Project Settings.


#include "Curve.h"
#include "MathUtils.h"

// Sets default values for this component's properties
UCurve::UCurve()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCurve::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCurve::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector UCurve::GetPosition(float t)
{
	return MathUtils::CubicBezier(A, B, C, D, t);
}

FVector UCurve::GetPositionMat(float t, FMatrix localToWorldMatrix)
{
	return localToWorldMatrix.TransformVector(GetPosition(t));
}

