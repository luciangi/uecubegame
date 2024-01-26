#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACube.h"
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTetracubeCollisionEvent);

UCLASS()
class UECUBEGAME_API ATetracube : public AActor
{
	GENERATED_BODY()

public:
	ATetracube();

	void SetDropSpeed(float NewDropSpeed);

	FTetracubeCollisionEvent &GetOnTetracubeCollision();

	void StartDropping();

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
	TSubclassOf<ACube> CubeBlueprintClass;

	virtual void OnConstruction(const FTransform &Transform) override;

private:
	float DropSpeed;
	FVector Color;
	UStaticMeshComponent *Cubes[4];
	FTimerHandle DropTimerHandle;
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTetracubeCollisionEvent OnTetracubeCollision;

	static ETetracube3DShape GetRandomTetracube3DShape();

	void OnDropTimer();
	bool ShouldDropActor();
	bool CubeWillHitWorldStatic(UStaticMeshComponent *Cube);
	void DropActor();
	void SetCubesCollisionToWorldStatic();
};
