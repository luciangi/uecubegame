#include "ATetracube.h"

ATetracube::ATetracube()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);

	for (int i = 0; i < 4; i++)
	{
		FString SubobjectName = "Cube" + FString::Printf(TEXT("%d"), i);
		Cubes[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(*SubobjectName));
		Cubes[i]->SetupAttachment(DefaultSceneRoot);
	}
}

void ATetracube::OnConstruction(const FTransform &Transform)
{
	Super::OnConstruction(Transform);

	FVector BaseColor;
	float Unit = 50.0f;

	switch (Shape)
	{
	case ETetracubeShape3D::I_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 2 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 3 * Unit));
		BaseColor = FVector(0.057805f, 1.f, 1.f);
		break;
	case ETetracubeShape3D::J_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, -1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 2 * Unit));
		BaseColor = FVector(0.f, 0.f, 1.f);
		break;
	case ETetracubeShape3D::L_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 2 * Unit));
		BaseColor = FVector(1.f, 0.219526f, 0.f);
		break;
	case ETetracubeShape3D::O_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 1 * Unit));
		BaseColor = FVector(1.f, 1.f, 0.f);
		break;
	case ETetracubeShape3D::S_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, -1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 1 * Unit));
		BaseColor = FVector(0.f, 1.f, 0.f);
		break;
	case ETetracubeShape3D::T_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, -1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		BaseColor = FVector(1.f, 0.f, 1.f);
		break;
	case ETetracubeShape3D::Z_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, -1 * Unit, 1 * Unit));
		BaseColor = FVector(1.f, 0.f, 0.f);
		break;
	case ETetracubeShape3D::Branch_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(1 * Unit, 0 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 1 * Unit));
		BaseColor = FVector(0.215861f, 0.029557f, 0.f);
		break;
	case ETetracubeShape3D::Right_Screw:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(-1 * Unit, 0 * Unit, 0 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(-1 * Unit, 0 * Unit, 1 * Unit));
		BaseColor = FVector(0.051269f, 0.051269f, 0.051269f);
		break;
	case ETetracubeShape3D::LeftScrew:
		Cubes[0]->SetRelativeLocation(FVector(0 * Unit, 0 * Unit, 0 * Unit));
		Cubes[1]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 0 * Unit));
		Cubes[2]->SetRelativeLocation(FVector(-1 * Unit, 0 * Unit, 0 * Unit));
		Cubes[3]->SetRelativeLocation(FVector(0 * Unit, 1 * Unit, 1 * Unit));
		BaseColor = FVector(0.552011f, 0.552011f, 0.552011f);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		Cubes[i]->SetStaticMesh(StaticMesh);
		Cubes[i]->SetMaterial(0, Material);
		Cubes[i]->SetVectorParameterValueOnMaterials("BaseColor", BaseColor);
	}
}
