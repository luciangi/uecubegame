#include "ATetracube.h"

ATetracube::ATetracube()
{
	USceneComponent *DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);

	for (int i = 0; i < 4; i++)
	{
		FString SubobjectName = "Cube" + FString::Printf(TEXT("%d"), i);
		Cubes[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(*SubobjectName));
		Cubes[i]->SetupAttachment(DefaultSceneRoot);
	}

	Shape = ATetracube::GetRandomTetracube3DShape();
}

void ATetracube::OnConstruction(const FTransform &Transform)
{
	Super::OnConstruction(Transform);

	switch (Shape)
	{
	case ETetracube3DShape::IShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 2 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 3 * CubeSize));
		Color = FVector(0.057805f, 1.f, 1.f);
		break;
	case ETetracube3DShape::JShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 2 * CubeSize));
		Color = FVector(0.f, 0.f, 1.f);
		break;
	case ETetracube3DShape::LShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 2 * CubeSize));
		Color = FVector(1.f, 0.219526f, 0.f);
		break;
	case ETetracube3DShape::OShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 1 * CubeSize));
		Color = FVector(1.f, 1.f, 0.f);
		break;
	case ETetracube3DShape::SShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 1 * CubeSize));
		Color = FVector(0.f, 1.f, 0.f);
		break;
	case ETetracube3DShape::TShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Color = FVector(1.f, 0.f, 1.f);
		break;
	case ETetracube3DShape::ZShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 1 * CubeSize));
		Color = FVector(1.f, 0.f, 0.f);
		break;
	case ETetracube3DShape::BranchShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(1 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Color = FVector(0.215861f, 0.029557f, 0.f);
		break;
	case ETetracube3DShape::RightScrewShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(-1 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(-1 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Color = FVector(0.051269f, 0.051269f, 0.051269f);
		break;
	case ETetracube3DShape::LeftScrewShape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(-1 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 1 * CubeSize));
		Color = FVector(0.552011f, 0.552011f, 0.552011f);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		Cubes[i]->SetStaticMesh(CubeStaticMesh);
		Cubes[i]->SetMaterial(0, CubeMaterial);
		Cubes[i]->SetVectorParameterValueOnMaterials(FName(*CubeMaterialColorParameterName), Color);
	}

	SetActorLocation(SpawnLocation);
}

void ATetracube::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(DropTimerHandle, this, &ATetracube::OnDropTimer, DropSpeed, true);
}

ETetracube3DShape ATetracube::GetRandomTetracube3DShape()
{
	uint8 RandomIndex = FMath::RandRange(0, static_cast<uint8>(ETetracube3DShape::ZShape));
	return static_cast<ETetracube3DShape>(RandomIndex);
};

void ATetracube::OnDropTimer()
{
	if (ShouldDropActor())
	{
		DropActor();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DropTimerHandle);
		SetCubesCollisionToWorldStatic();
		GetWorld()->SpawnActor<ATetracube>(TetracubeBlueprintClass, FTransform::Identity);
	}
}

bool ATetracube::ShouldDropActor()
{
	for (UStaticMeshComponent *Cube : Cubes)
	{

		if (CubeWillHitWorldStatic(Cube))
		{
			return false;
		}
	}

	return true;
}

bool ATetracube::CubeWillHitWorldStatic(UStaticMeshComponent *Cube)
{
	FHitResult HitResult;

	FVector StartLocation = Cube->GetComponentLocation();
	FVector EndLocation = StartLocation;
	EndLocation.Z -= CubeSize;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // Ignore this actor in the trace

	return GetWorld()->LineTraceSingleByObjectType(
		HitResult,
		StartLocation,
		EndLocation,
		FCollisionObjectQueryParams(ObjectTypes),
		CollisionParams);
}

void ATetracube::DropActor()
{
	FVector NewLocation = GetActorLocation();
	NewLocation.Z -= CubeSize;
	SetActorLocation(NewLocation);
}

void ATetracube::SetCubesCollisionToWorldStatic()
{
	for (UStaticMeshComponent *Cube : Cubes)
	{
		Cube->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	}
}
