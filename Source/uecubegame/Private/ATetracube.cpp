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

	switch (Shape)
	{
	case ETetracubeShape3D::I_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 2 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 3 * CubeSize));
		BaseColor = FVector(0.057805f, 1.f, 1.f);
		break;
	case ETetracubeShape3D::J_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 2 * CubeSize));
		BaseColor = FVector(0.f, 0.f, 1.f);
		break;
	case ETetracubeShape3D::L_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 2 * CubeSize));
		BaseColor = FVector(1.f, 0.219526f, 0.f);
		break;
	case ETetracubeShape3D::O_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(1.f, 1.f, 0.f);
		break;
	case ETetracubeShape3D::S_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(0.f, 1.f, 0.f);
		break;
	case ETetracubeShape3D::T_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(1.f, 0.f, 1.f);
		break;
	case ETetracubeShape3D::Z_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, -1 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(1.f, 0.f, 0.f);
		break;
	case ETetracubeShape3D::Branch_Shape:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(1 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(0.215861f, 0.029557f, 0.f);
		break;
	case ETetracubeShape3D::Right_Screw:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(-1 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(-1 * CubeSize, 0 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(0.051269f, 0.051269f, 0.051269f);
		break;
	case ETetracubeShape3D::LeftScrew:
		Cubes[0]->SetRelativeLocation(FVector(0 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[1]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 0 * CubeSize));
		Cubes[2]->SetRelativeLocation(FVector(-1 * CubeSize, 0 * CubeSize, 0 * CubeSize));
		Cubes[3]->SetRelativeLocation(FVector(0 * CubeSize, 1 * CubeSize, 1 * CubeSize));
		BaseColor = FVector(0.552011f, 0.552011f, 0.552011f);
		break;
	}

	for (int i = 0; i < 4; i++)
	{
		Cubes[i]->SetStaticMesh(StaticMesh);
		Cubes[i]->SetMaterial(0, Material);
		Cubes[i]->SetVectorParameterValueOnMaterials(FName(*MaterialColorParameterName), BaseColor);
	}
}

void ATetracube::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(DropTimerHandle, this, &ATetracube::OnDropTimer, DropSpeed, true);
}

void ATetracube::OnDropTimer()
{
	if (ShouldDropActor())
	{
		DropActor();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(DropTimerHandle);

		FTransform NewActorTransform = GetActorTransform();
	}
}

bool ATetracube::ShouldDropActor()
{
	TArray<USceneComponent *> ChildrenComponents;
	GetRootComponent()->GetChildrenComponents(true, ChildrenComponents);

	for (USceneComponent *ChildComponent : ChildrenComponents)
	{

		if (ComponentWillHitWorldStatic(ChildComponent))
		{
			return false;
		}
	}

	return true;
}

bool ATetracube::ComponentWillHitWorldStatic(USceneComponent *Component)
{
	FHitResult HitResult;

	FVector StartLocation = Component->GetComponentLocation();
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
