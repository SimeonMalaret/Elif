// Fill out your copyright notice in the Description page of Project Settings.

#include "FreeFollowView.h"
#include "MathUtils.h"
#include "CameraManager.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

void UFreeFollowView::BeginPlay() 
{
    player = Cast<ADreamHuntersCharacter, ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	SetActive(true);
}

void UFreeFollowView::SetActiveView(bool isActive) 
{
    if (isActive)
    {
        UCameraManager::views->Add(this);
    }
    else
    {
        UCameraManager::views->Remove(this);
    }
}

CameraConfig* UFreeFollowView::GetConfiguration() 
{
    CameraConfig* config = new CameraConfig();
    config->yaw = yaw;
    config->pitch = _pitch;
    config->roll = _roll;
    config->fov = fieldOfView;
    config->pivot = positionCamera;
    config->distance = 0;

    return config;
}

void UFreeFollowView::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    GetOwner()->SetActorLocation(player->GetActorLocation());
    yaw -= FMath::RadiansToDegrees(player->Controller->GetInputAxisValue(TEXT("TurnRate")) * yawSpeed * DeltaTime);

    curvePosition += player->Controller->GetInputAxisValue(TEXT("LookUpRate")) * curveSpeed * DeltaTime;
    curvePosition = FMath::Clamp(curvePosition, 0.0f, 1.0f);

    _pitch = Lerp(pitch, curvePosition);
    _roll = Lerp(roll, curvePosition);
    fieldOfView = Lerp(fov, curvePosition);

    FMatrix newRotationMat = MathUtils::TRSMatrix(GetOwner()->GetActorLocation(), FQuat::MakeFromEuler(FVector(0, yaw, 0)), FVector::OneVector);
    
    positionCamera = curve->GetPositionMat(curvePosition, newRotationMat);
}

float UFreeFollowView::Lerp(float list[], float position)
{
    if (position <= 0.5)
    {
        return FMath::Lerp(list[0], list[1], position * 2);
    }
    else
    {
        return FMath::Lerp(list[1], list[2], (position - 0.5f) * 2);
    }
}