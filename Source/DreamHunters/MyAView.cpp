// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAView.h"

UMyAView::UMyAView() {
    roll = 0;
    fov = 60.0f;

    distance = 0;
    speed = 1.0f;
}

void UMyAView::BeginPlay()
{
    Super::BeginPlay();
    // ...
    cameraConfig = new CameraConfig();
}

void UMyAView::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	railPosition = rail->NearPosOnRail(target->GetActorLocation());
}

CameraConfig* UMyAView::GetConfiguration() {
    cameraConfig->pivot = rail->GetPosition(railPosition);

    FVector dir = (target->GetActorLocation() - cameraConfig->pivot);
    dir.Normalize();

    cameraConfig->yaw = FMath::RadiansToDegrees(FMath::Atan2(dir.X, dir.Z));
    cameraConfig->pitch = FMath::RadiansToDegrees(-FMath::Asin(dir.Y));
    cameraConfig->roll = roll;
    cameraConfig->distance = 0;
    cameraConfig->fov = fov;

    return cameraConfig;
}
