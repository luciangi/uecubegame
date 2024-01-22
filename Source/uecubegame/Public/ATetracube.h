#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATetracube.generated.h"

UENUM(BlueprintType)
enum class ETetracube3DShape : uint8
{
	IShape,
	JShape,
	LShape,
	OShape,
	SShape,
	TShape,
	ZShape,
	BranchShape,
	RightScrewShape,
	LeftScrewShape
};

UCLASS()
class UECUBEGAME_API ATetracube : public AActor
{
	GENERATED_BODY()

public:
	ATetracube();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	UStaticMesh *CubeStaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	UMaterial *CubeMaterial;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	float CubeSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	FString CubeMaterialColorParameterName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ATetracube> ChildBlueprintClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector SpawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DropSpeed;

	virtual void OnConstruction(const FTransform &Transform) override;
	virtual void BeginPlay() override;

private:
	ETetracube3DShape Shape;
	USceneComponent *DefaultSceneRoot;
	UStaticMeshComponent *Cubes[4];
	FTimerHandle DropTimerHandle;

	static ETetracube3DShape GetRandomTetracube3DShape()
	{
		uint8 RandomIndex = FMath::RandRange(0, static_cast<uint8>(ETetracube3DShape::ZShape));
		return static_cast<ETetracube3DShape>(RandomIndex);
	};
	void OnDropTimer();
	bool ShouldDropActor();
	bool ComponentWillHitWorldStatic(USceneComponent *Component);
	void DropActor();
	void SpawnNewInstance();
};
