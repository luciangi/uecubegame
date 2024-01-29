#pragma once

#include "Cube.h"
#include "Tetracube.generated.h"

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
	/** Constructors */
	ATetracube();

	/** Getters and Setters */
	FTetracubeCollisionEvent &GetOnTetracubeCollision();

	void SetDropSpeed(float NewDropSpeed);

	/** Public */
	void StartDropping();
	void Rotate();
	void MoveLeft();
	void MoveRight();
	void Accelerate();
	void Decelerate();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	UStaticMesh *CubeStaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	UMaterialInstance *CubeMaterialInstance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Cube")
	FString CubeMaterialInstanceColorParameterName;
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
	TArray<UStaticMeshComponent*> Cubes;
	FTimerHandle DropTimerHandle;
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTetracubeCollisionEvent OnTetracubeCollision;

	void OnDropTimer();
	void SpawnWorldStaticCubes();
	bool WillHitWorldStatic(FTransform Transform);
	bool CubeWillHitWorldStatic(UStaticMeshComponent *Cube, FTransform Transform);
	void AccelerateTime();
	void ResetTime();
	void SetActorTransform(FTransform NewTransform);
};
