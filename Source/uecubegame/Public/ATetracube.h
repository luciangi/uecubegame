#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATetracube.generated.h"

UENUM(BlueprintType)
enum class ETetracubeShape3D : uint8
{
	I_Shape,
	J_Shape,
	L_Shape,
	O_Shape,
	S_Shape,
	T_Shape,
	Z_Shape,
	Branch_Shape,
	Right_Screw,
	LeftScrew
};

UENUM(BlueprintType)
enum class ETetracubeShape2D : uint8
{
	I_Shape,
	J_Shape,
	L_Shape,
	O_Shape,
	S_Shape,
	T_Shape,
	Z_Shape
};

UCLASS()
class UECUBEGAME_API ATetracube : public AActor
{
	GENERATED_BODY()

public:
	ATetracube();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh *StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterial *Material;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CubeSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString MaterialColorParameterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETetracubeShape3D Shape;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DropSpeed;

	virtual void OnConstruction(const FTransform &Transform) override;
	virtual void BeginPlay() override;

private:
	USceneComponent *DefaultSceneRoot;
	UStaticMeshComponent *Cubes[4];
	FTimerHandle DropTimerHandle;

	void OnDropTimer();
	bool ShouldDropActor();
	bool ComponentWillHitWorldStatic(USceneComponent *Component);
	void DropActor();
};
