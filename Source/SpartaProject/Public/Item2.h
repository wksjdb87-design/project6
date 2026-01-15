#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item2.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem2 : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem2();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Properties")
	float SpinSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void StartLocation();
};
