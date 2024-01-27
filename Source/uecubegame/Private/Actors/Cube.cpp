#include "Actors/Cube.h"

/** Constructors */
ACube::ACube()
{
	USceneComponent *DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Cube")));
	Cube->SetupAttachment(DefaultSceneRoot);
	Cube->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
}

/** Getters and Setters */
void ACube::SetColor(FVector NewColor)
{
	Color = NewColor;
}

/** Blueprint */
void ACube::OnConstruction(const FTransform &Transform)
{
	Super::OnConstruction(Transform);

	Cube->SetStaticMesh(StaticMesh);
	Cube->SetMaterial(0, MaterialInstance);
	Cube->SetVectorParameterValueOnMaterials(FName(*MaterialInstanceColorParameterName), Color);
}
