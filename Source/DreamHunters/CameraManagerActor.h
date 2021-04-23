// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AView.h"
#include "CameraManagerActor.generated.h"

UCLASS()
class DREAMHUNTERS_API ACameraManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraManagerActor();

	UPROPERTY(EditAnywhere)
	ACameraActor* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<UAView*> views;
	float cameraMoveSpeed;
};
