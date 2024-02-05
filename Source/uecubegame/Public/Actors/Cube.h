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
	float &GetTargetZLocation();

	void SetColor(FVector NewColor);

	/** Public */
	void DropTargetZLocation();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh *StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance *MaterialInstance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString MaterialInstanceColorParameterName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CubeSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FlashSpeed;

	virtual void OnConstruction(const FTransform &Transform) override;
	virtual void Tick(float DeltaTime) override;

private:
	UStaticMeshComponent *Cube;
	FVector Color;
	FTimerHandle FlashTimerHandle;
	float TargetZLocation;

	void StartFlash();
	void OnFlashTimer();
};
