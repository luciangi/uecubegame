#include "Actors/CheckLines.h"

/** Constructors */
ACheckLines::ACheckLines()
{
	USceneComponent *DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);

	for (int i = 0; i <= 15; i++)
	{
		FString SubobjectName = "BoxCollision" + FString::Printf(TEXT("%d"), i);
		UBoxComponent *Box = CreateDefaultSubobject<UBoxComponent>(FName(*SubobjectName));
		Box->SetupAttachment(DefaultSceneRoot);
		BoxCollisionComponents.Add(Box);
	}
}

/** Blueprint */
void ACheckLines::OnConstruction(const FTransform &Transform)
{
	Super::OnConstruction(Transform);

	float ZLocation = CubeSize;
	for (UBoxComponent *BoxCollisionComponent : BoxCollisionComponents)
	{
		ZLocation += CubeSize;
		BoxCollisionComponent->SetBoxExtent(FVector(0.1f, 5 * CubeSize, 0.1f));
		BoxCollisionComponent->SetRelativeLocation(FVector(0, 0, ZLocation));
	}
}

void ACheckLines::BeginPlay()
{
	Super::BeginPlay();
}
