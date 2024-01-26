#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACube.generated.h"

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
	UMaterial *Material;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString MaterialColorParameterName;

	UStaticMeshComponent *Cube;

	virtual void OnConstruction(const FTransform &Transform) override;

private:
	FVector Color;
};
