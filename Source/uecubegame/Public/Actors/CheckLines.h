#pragma once

#include "Components/BoxComponent.h"
#include "CheckLines.generated.h"

UCLASS()
class UECUBEGAME_API ACheckLines : public AActor
{
	GENERATED_BODY()

public:
	/** Constructors */
	ACheckLines();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CubeSize;

	void OnConstruction(const FTransform &Transform);
	virtual void BeginPlay() override;

private:
	TArray<UBoxComponent *> BoxCollisionComponents;
};
