#include "Actors/CheckLines.h"
#include "Kismet/KismetSystemLibrary.h"

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

	float ZLocation = 0;
	for (UBoxComponent *BoxCollisionComponent : BoxCollisionComponents)
	{
		ZLocation += CubeSize;
		BoxCollisionComponent->SetBoxExtent(FVector(0.1f, 5 * CubeSize, 0.1f));
		BoxCollisionComponent->SetRelativeLocation(FVector(0, 0, ZLocation));
	}
}

/** Public */
TArray<float> ACheckLines::CheckCompletedLines(UClass *ActorClassFilter)
{
	TArray<float> CompletedLinesZLocation;
	for (UBoxComponent *BoxCollisionComponent : BoxCollisionComponents)
	{
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

		TArray<AActor *> ActorsToIgnore;
		TArray<AActor *> OutActors;

		UKismetSystemLibrary::ComponentOverlapActors(
			BoxCollisionComponent,
			BoxCollisionComponent->GetComponentTransform(),
			ObjectTypes,
			ActorClassFilter,
			ActorsToIgnore,
			OutActors);

		if (OutActors.Num() >= 10)
		{
			CompletedLinesZLocation.Add(BoxCollisionComponent->GetComponentLocation().Z);
		}
	}

	return CompletedLinesZLocation;
}
