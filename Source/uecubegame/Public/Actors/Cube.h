#pragma once

#include "Cube.generated.h"

UCLASS()
class UECUBEGAME_API ACube : public AActor
{
	GENERATED_BODY()

public:
	/** Constructors */
	ACube();

	/** Getter and Setters */
	void SetColor(FVector NewColor);

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh *StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance *MaterialInstance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString MaterialInstanceColorParameterName;

	virtual void OnConstruction(const FTransform &Transform) override;

private:
	UStaticMeshComponent *Cube;
	FVector Color;
};
