#include "Item3.h"

void AItem3::ResetActorPosition()
{
	SetActorLocation(FVector(-2000.0f, 3000.0f, 250.0f));   // ZeroVector를 사용하게 되면 바로 원점으로 돌아감
}

void AItem3::StartLocation()
{
	SetActorLocation(FVector(-2000.0f, 3000.0f, 250.0f));
}

AItem3::AItem3()
{
	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 200.0f;
	MaxRange = 2000.0f;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void AItem3::BeginPlay()
{
	Super::BeginPlay();

	StartLocation();
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(5.0f));
}

void AItem3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	NewLocation.X += MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);

	if (NewLocation.X > MaxRange)
	{
		ResetActorPosition();
	}
}

