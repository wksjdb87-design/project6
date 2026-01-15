// Fill out your copyright notice in the Description page of Project Settings.


#include "Item2.h"

void AItem2::StartLocation()
{
	SetActorLocation(FVector(-2000.0f, -3000.0f, 250.0f));
}

AItem2::AItem2()
{
	PrimaryActorTick.bCanEverTick = true;
	SpinSpeed = 100.0f;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void AItem2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation();
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(5.0f));
}

void AItem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(SpinSpeed))   // FMath::IsNearlyZero() 0과 근접한 수가 있다면 0으로 간주하는 함수
	{
		AddActorLocalRotation(FRotator(0.0f, SpinSpeed * DeltaTime, 0.0f));
	}
}