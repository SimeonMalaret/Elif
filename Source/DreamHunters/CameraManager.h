// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AView.h"
#include "CameraManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DREAMHUNTERS_API UCameraManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<UAView*> views;
	// Sets default values for this component's properties
	UCameraManager();

private:
	
	UPROPERTY(EditAnywhere)
	ACameraActor* Camera;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float cameraMoveSpeed;

	
};
