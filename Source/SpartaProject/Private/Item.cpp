#include "Item.h"

DEFINE_LOG_CATEGORY(LogSparta); 
// 헤더에서 선언했던 로그 카테고리를 정의하는 함수

void AItem::StartLocation()
{
	SetActorLocation(FVector(-2000.0f, 1000.0f, 250.0f));
}

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;     // 매 프레임마다 Tick 함수를 호출할지 여부를 설정하는 변수
	MoveSpeed = 200.0f;
	MaxRange = 2000.0f;
	StartXLocation = -2000;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	UE_LOG(LogSparta, Warning, TEXT("%s Constructor"), *GetName());  // *GetName() 현재 소환되어 있는 아이템의 이름을 가져옴
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	StartLocation();  // 위치할 좌표를 설정함
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));   // pitch(y축), yaw(z축), roll(x축) 순으로 값을 설정함
	SetActorScale3D(FVector(5.0f));    // x축 2배, y축 1배, z축 1배 크기로 설정 전부 같은 크기로 배율을 주고싶으면 (2.0f) 이렇게 하나의 값으로도 설정가능
}

void AItem::Tick(float DeltaTime)  // DeltaTime : 프레임당 시간
{
	Super::Tick(DeltaTime);

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

// 생성자 - 메모리에 생김, 딱 한번 호출됨
// PostInitializeComponents() - 컴포넌트들이 완성된 직후 호출, 컴포넌트끼리 테이터 주고받기, 상호작용
// BeginPlay() - 배치(spawn) 직후 호출됨
// Tick(float DeltaTime) - 매 프레임마다 호출됨
// Destoyed() - 삭제 되기 직전에 호출됨
// EndPlay() - 게임 종료, 파괴, 레벨 전환 때 호출됨

// D -> E d가 불리면 e도 같이 불려옴, 명시적으로 호출됨
// 그냥 게임을 꺼버리게 되면 EndPlay만 호출됨, 모든게 끝나는 상황에 호출됨
