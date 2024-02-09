#include "Core/Actors/CheckLines.h"
#include "Kismet/KismetSystemLibrary.h"

/** Constructors */
ACheckLines::ACheckLines()
{
	USceneComponent *DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(DefaultSceneRoot);

	for (int i = 0; i < 20; i++)
	{
		FString SubobjectName = "CompletedLinesBoxCollision" + FString::Printf(TEXT("%d"), i);
		UBoxComponent *Box = CreateDefaultSubobject<UBoxComponent>(FName(*SubobjectName));
		Box->SetupAttachment(DefaultSceneRoot);
		CompletedLinesBoxCollisionComponents.Add(Box);
	}

	EndLineBoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("EndLineBoxCollision"));
	EndLineBoxCollisionComponent->SetupAttachment(DefaultSceneRoot);
}

/** Blueprint */
void ACheckLines::BeginPlay()
{
	Super::BeginPlay();

	FVector BoxExtent(0.1f, 5 * CubeSize, 0.1f);
	float ZLocation = CubeSize;
	for (UBoxComponent *BoxCollisionComponent : CompletedLinesBoxCollisionComponents)
	{
		BoxCollisionComponent->SetBoxExtent(BoxExtent);
		BoxCollisionComponent->SetRelativeLocation(FVector(0, 0, ZLocation));
		ZLocation += CubeSize;
	}

	EndLineBoxCollisionComponent->SetBoxExtent(BoxExtent);
	EndLineBoxCollisionComponent->SetRelativeLocation(FVector(0, 0, ZLocation));
}

/** Public */
bool ACheckLines::CheckOverlapWithEndLine(UClass *ActorClassFilter)
{
	return GetOverlappingActorsCount(ActorClassFilter, EndLineBoxCollisionComponent) > 0;
}

TArray<float> ACheckLines::CheckOverlapWithCompletedLines(UClass *ActorClassFilter)
{
	TArray<float> CompletedLinesZLocation;
	for (UBoxComponent *BoxCollisionComponent : CompletedLinesBoxCollisionComponents)
	{
		if (GetOverlappingActorsCount(ActorClassFilter, BoxCollisionComponent) >= 10)
		{
			CompletedLinesZLocation.Add(BoxCollisionComponent->GetComponentLocation().Z);
		}
	}

	return CompletedLinesZLocation;
}

/** Private */
int ACheckLines::GetOverlappingActorsCount(UClass *ActorClassFilter, UBoxComponent *BoxComponent)
{
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

	TArray<AActor *> ActorsToIgnore;
	TArray<AActor *> OverlappingActors;

	UKismetSystemLibrary::ComponentOverlapActors(
		BoxComponent,
		BoxComponent->GetComponentTransform(),
		ObjectTypes,
		ActorClassFilter,
		ActorsToIgnore,
		OverlappingActors);

	return OverlappingActors.Num();
}
