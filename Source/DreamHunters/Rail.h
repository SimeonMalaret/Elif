// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rail.generated.h"

UCLASS()
class DREAMHUNTERS_API ARail : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARail();

	UPROPERTY(EditAnywhere)
	bool isLoop;

private:

	float length;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetLength();
	FVector GetPosition(float distance);
	float NearPosOnRail(FVector target);

private:

	FVector GetProjectPoint(FVector target, FVector node, FVector nextNode);

	UPROPERTY(EditAnywhere)
		TArray<AActor*> waypoints;
};
