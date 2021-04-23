// Fill out your copyright notice in the Description page of Project Settings.


#include "Rail.h"

// Sets default values
ARail::ARail()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARail::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARail::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ARail::GetLength() {
	return length;
}

FVector ARail::GetPosition(float distance) {

	if (isLoop) {

        while (distance > length)
        {
            distance -= length;
        }
        while (distance < 0)
        {
            distance += length;
        }

    }
    else
    {
        if (distance >= length) return waypoints[waypoints.Num() - 1]->GetActorLocation();
        else if (distance <= 0) return waypoints[0]->GetActorLocation();
    }

    for (int i = 0; i < waypoints.Num(); i++)
    {
        int j = i + 1;
        if (j == waypoints.Num())
        {
            j = 0;
        }

        if (distance > FVector::Distance(waypoints[j]->GetActorLocation(), waypoints[i]->GetActorLocation()))
        {
            distance -= FVector::Distance(waypoints[j]->GetActorLocation(), waypoints[i]->GetActorLocation());
        }
        else
        {
            FVector tmp = waypoints[j]->GetActorLocation() - waypoints[i]->GetActorLocation();
            tmp.Normalize();
            return waypoints[i]->GetActorLocation() + tmp * distance;
        }
    }

    return FVector::ZeroVector;
}

float ARail::NearPosOnRail(FVector target) {

    float distance = INFINITY;
    int node = 0;

    for (int i = 0; i < waypoints.Num(); i++)
    {
        if (FVector::Distance(target, waypoints[i]->GetActorLocation()) < distance)
        {
            distance = FVector::Distance(target, waypoints[i]->GetActorLocation());
            node = i;
        }
    }

    float distanceOnRail = 0;

    for (int i = 0; i < node; i++)
    {
        distanceOnRail += FVector::Distance(waypoints[i]->GetActorLocation(), waypoints[i + 1]->GetActorLocation());
    }

    ////////////////////////////////////////////////////

    FVector dir;
    FVector dir2;

    FVector nodePos = waypoints[node]->GetActorLocation();

    if (node >= waypoints.Num() - 1)
        dir = waypoints[0]->GetActorLocation() - nodePos;
    else
        dir = waypoints[node + 1]->GetActorLocation() - nodePos;


    if (node == 0)
        dir2 = waypoints[waypoints.Num() - 1]->GetActorLocation() - nodePos;
    else
        dir2 = waypoints[node - 1]->GetActorLocation() - nodePos;

    FVector noNormalDir = dir;
    dir.Normalize();

    FVector noNormalDir2 = dir2;
    dir2.Normalize();

    float dot1 = FVector::DotProduct(dir, target - nodePos);

    dot1 = FMath::Clamp(dot1, 0.0f, FMath::Sqrt(noNormalDir.X * noNormalDir.X + noNormalDir.Y * noNormalDir.Y + noNormalDir.Z * noNormalDir.Z));

    float dot2 = FVector::DotProduct(dir2, target - nodePos);

    dot1 = FMath::Clamp(dot2, 0.0f, FMath::Sqrt(noNormalDir2.X * noNormalDir2.X + noNormalDir2.Y * noNormalDir2.Y + noNormalDir2.Z * noNormalDir2.Z));

    FVector pos1 = nodePos + dir * dot1;
    FVector pos2 = nodePos + dir2 * dot2;



    if (FVector::Distance(pos1, target) < FVector::Distance(pos2, target))
    {
        distanceOnRail += dot1;
    }
    else
    {
        distanceOnRail -= dot2;
    }



    return distanceOnRail;
}

FVector ARail::GetProjectPoint(FVector target, FVector node, FVector nextNode)
{
    FVector direction = nextNode - node;

    FVector tmp = node + FMath::Clamp(FVector::DotProduct(target - node, direction), 0.0f, FVector::Distance(node, nextNode)) * direction;
    return tmp;
}

