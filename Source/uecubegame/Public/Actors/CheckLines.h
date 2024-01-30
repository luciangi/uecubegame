#pragma once

#include "Components/BoxComponent.h"
#include "Cube.h"
#include "CheckLines.generated.h"

UCLASS()
class UECUBEGAME_API ACheckLines : public AActor
{
	GENERATED_BODY()

public:
	/** Constructors */
	ACheckLines();

	/** Public */
	TArray<float> CheckCompletedLines(UClass *ActorClassFilter);

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CubeSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ACube> CubeBlueprintClass;

	void OnConstruction(const FTransform &Transform);

private:
	TArray<UBoxComponent *> BoxCollisionComponents;
};
