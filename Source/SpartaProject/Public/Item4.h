#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item4.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem4 : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem4();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Properties")
	float SpinSpeed;

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

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void StartLocation();
};
