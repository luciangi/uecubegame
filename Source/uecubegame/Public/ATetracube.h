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

UCLASS() class UECUBEGAME_API ATetracube : public AActor
{
	GENERATED_BODY()

public:
	ATetracube();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh *StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterial *Material;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETetracubeShape3D Shape;

	USceneComponent *DefaultSceneRoot;
	UStaticMeshComponent *Cubes[4];

	virtual void OnConstruction(const FTransform &Transform);
	// virtual void BeginPlay() override;
};
