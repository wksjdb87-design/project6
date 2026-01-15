#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"   // 리플렉션 시스템을 위한 헤더 파일, 항상 헤더 마지막에 위치

DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All);
// DECLARE_LOG_CATEGORY_EXTERN : 로고를 선언하는 함수
// LogSparta : 카테고리의 이름, Warning : 기본 로고 심각도 설정 , All : 모든 빌드 설정에서 사용 가능

UCLASS() // () 안에 Blueprintable, BlueprintType 을 쓰거나 안 써도 동일하게 사용 가능함, not 을 붙이게 되면 상속은 불가능
class SPARTAPROJECT_API AItem : public AActor  // SPARTAPROJECT_API 는 모듈 밖으로 내보내기 위한 매크로
{
	GENERATED_BODY()   //UCLASS()와 GENERATED_BODY()는 항상 쌍으로 사용, GENERATED_BODY()는 리플렉션 데이터를 자동으로 생성하기 위함
	
public:	
	AItem();

protected:    // 컴포넌트 앞에 UPROPERTY()를 붙혀주면 리플렉션에 등록이 됨
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Properties")
	float MoveSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Properties")
	float MaxRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Properties")
	float StartXLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components") 
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components") 
	UStaticMeshComponent* StaticMeshComp;

	// VisibleAnywhere는 수정은 불가능, EditDefaultsOnly는 디폴트만 수정이 가능하고, 인스턴스에서는 수정 불가, EditAnywhere는  디폴트나 인스턴스에서 둘 다 수정 가능
	// BlueprintReadOnly는 get만 가능, BlueprintReadWrite는 get 과 set 둘 다 가능

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void StartLocation();

	// UFUNCTION는 함수를 리플렉션에 등록하고 싶을 때 사용
	// BlueprintCallable는 블루프린트에서 함수를 호출할 수 있게됨, BlueprintPure는 블루프린트에서 값만 반환 받는 함수로 호출 가능, BlueprintImplementableEvent는 구현은 
};
