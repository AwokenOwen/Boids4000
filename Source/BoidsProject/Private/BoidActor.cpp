// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidActor.h"

// Sets default values
ABoidActor::ABoidActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh")); 

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'")); 
	SphereMesh->SetStaticMesh(SphereMeshAsset.Object);

	RootComponent = SphereMesh; 

	SphereMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));

	Velocity = FVector(FMath::RandRange(-50.f, 50.f), FMath::RandRange(-50.f, 50.f), FMath::RandRange(-50.f, 50.f));
}

// Called when the game starts or when spawned
void ABoidActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoidActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

