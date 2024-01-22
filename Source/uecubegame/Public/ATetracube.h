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
	FString CubeMaterialColorParameterName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	float CubeSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ATetracube> TetracubeBlueprintClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector SpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropSpeed;

	virtual void OnConstruction(const FTransform &Transform) override;
	virtual void BeginPlay() override;

private:
	ETetracube3DShape Shape;
	FVector Color;
	UStaticMeshComponent *Cubes[4];
	FTimerHandle DropTimerHandle;

	static ETetracube3DShape GetRandomTetracube3DShape();
	void OnDropTimer();
	bool ShouldDropActor();
	bool CubeWillHitWorldStatic(UStaticMeshComponent *Cube);
	void DropActor();
	void SetCubesCollisionToWorldStatic();
};
