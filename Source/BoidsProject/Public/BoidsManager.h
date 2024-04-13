// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "BoidActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidsManager.generated.h"

UCLASS()
class BOIDSPROJECT_API ABoidsManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidsManager();
	TArray<ABoidActor*> boidList;
	FVector rule1(ABoidActor* boid);
	FVector rule2(ABoidActor* boid);
	FVector rule3(ABoidActor* boid);
	FVector rule4(ABoidActor* boid);
	void Limit_Speed(ABoidActor* boid);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
