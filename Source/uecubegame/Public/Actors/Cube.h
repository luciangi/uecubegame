#pragma once

#include "Cube.generated.h"

UCLASS()
class UECUBEGAME_API ACube : public AActor
{
	GENERATED_BODY()

public:
	ACube();

	void SetColor(FVector NewColor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh *StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance *MaterialInstance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString MaterialInstanceColorParameterName;

	UStaticMeshComponent *Cube;

	virtual void OnConstruction(const FTransform &Transform) override;

private:
	FVector Color;
};
