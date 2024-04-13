// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsManager.h"

// Sets default values
ABoidsManager::ABoidsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FVector ABoidsManager::rule1(ABoidActor* boid)
{
	FVector pc;

	for (ABoidActor* b : boidList)
	{
		if (b != boid)
		{
			pc += b->GetActorLocation();
		}
	}

	pc = pc / (boidList.Num() - 1);

	return (pc - boid->GetActorLocation()) / 1000.f;
}

FVector ABoidsManager::rule2(ABoidActor* boid)
{
	FVector c; 

	for (ABoidActor* b : boidList) 
	{
		if (b != boid)
		{
			if ((b->GetActorLocation() - boid->GetActorLocation()).Size() < 1000)
			{
				c = c - (b->GetActorLocation() - boid->GetActorLocation());
			}
		}
	}
	
	return c / 100000.f;
}

FVector ABoidsManager::rule3(ABoidActor* boid)
{
	FVector pv; 

	for (ABoidActor* b : boidList)
	{
		if (b != boid) 
		{
			pv += b->Velocity; 
		}
	}

	pv = pv / (boidList.Num() - 1); 

	return (pv - boid->Velocity) / 800000.f;
}

FVector ABoidsManager::rule4(ABoidActor* boid)
{
	FVector v(0.f);
	if (boid->GetActorLocation().X < -10000)
	{
		v.X = 10.f;
	}
	else if (boid->GetActorLocation().X > 10000)
	{
		v.X = -10.f;
	}
	if (boid->GetActorLocation().Y < -10000)
	{
		v.Y = 10.f;
	}
	else if (boid->GetActorLocation().Y > 10000)
	{
		v.Y = -10.f;
	}
	if (boid->GetActorLocation().Z < 0)
	{
		v.Z = 10.f;
	}
	else if (boid->GetActorLocation().Z > 10000)
	{
		v.Z = -10.f;
	}

	return v / 10.f;
}

void ABoidsManager::Limit_Speed(ABoidActor* boid)
{
	if (boid->Velocity.Size() > 50.f)
	{
		boid->Velocity = (boid->Velocity / boid->Velocity.Size()) * 50.f;
	}
}

// Called when the game starts or when spawned
void ABoidsManager::BeginPlay()
{
	Super::BeginPlay();
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			ABoidActor* boid = GetWorld()->SpawnActor<ABoidActor>();
			boid->SetActorLocation(FVector(x * 100.f, y * 100.f, 100.f));
			boidList.Add(boid);
		}
	}
}

// Called every frame
void ABoidsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (ABoidActor* b : boidList)
	{
		b->Velocity = b->Velocity + rule1(b) + rule2(b) + rule3(b) + rule4(b);
		Limit_Speed(b);
		b->SetActorLocation(b->GetActorLocation() + b->Velocity);
	}
}