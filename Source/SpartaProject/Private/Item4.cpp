#include "Item4.h"

void AItem4::StartLocation()
{
	SetActorLocation(FVector(-2000.0f, -1000.0f, 250.0f));
}

AItem4::AItem4()
{
	PrimaryActorTick.bCanEverTick = true;
	SpinSpeed = 100.0f;
	MoveSpeed = 200.0f;
	MaxRange = 2000.0f;
	StartXLocation = -2000.0f;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void AItem4::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation();
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(5.0f));
}

void AItem4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (!FMath::IsNearlyZero(SpinSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, SpinSpeed * DeltaTime, 0.0f));
	}

	FVector NewLocation = GetActorLocation();
	NewLocation.X += MoveSpeed * DeltaTime;

	if (MoveSpeed > 0.0f && NewLocation.X > MaxRange)
	{
		MoveSpeed *= -1;
	}

	if (MoveSpeed < 0.0f && NewLocation.X < StartXLocation)
	{
		MoveSpeed *= -1;
	}

	SetActorLocation(NewLocation);
}

