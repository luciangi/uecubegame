#include "Actors/Cube.h"

/** Constructors */
ACube::ACube()
{
	USceneComponent *DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Cube")));
	Cube->SetupAttachment(DefaultSceneRoot);
	Cube->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);

	PrimaryActorTick.bCanEverTick = true;
}

/** Getters and Setters */
float &ACube::GetTargetZLocation()
{
	return TargetZLocation;
}

void ACube::SetColor(FVector NewColor)
{
	Color = NewColor;
}

/** Public */
void ACube::DropTargetZLocation()
{
	TargetZLocation -= CubeSize;
}

/** Blueprint */
void ACube::OnConstruction(const FTransform &Transform)
{
	Super::OnConstruction(Transform);

	Cube->SetStaticMesh(StaticMesh);
	Cube->SetMaterial(0, MaterialInstance);
	Cube->SetVectorParameterValueOnMaterials(FName(*MaterialInstanceColorParameterName), Color);

	TargetZLocation = GetActorLocation().Z;
}

void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	long CurrentZLocation = CurrentLocation.Z;

	if (CurrentZLocation > TargetZLocation)
	{
		long ZLocation = FMath::Lerp(CurrentZLocation, TargetZLocation, DropSpeed);
		SetActorLocation(FVector(CurrentLocation.X, CurrentLocation.Y, ZLocation));
	}
}
