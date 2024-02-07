#include "Core/Actors/Cube.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

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
void ACube::Remove()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, GetActorLocation(), FRotator::ZeroRotator, true);
	Destroy();
}

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

	TargetZLocation = GetActorLocation().Z;

	StartFlash();
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

/** Private */
void ACube::StartFlash()
{
	FVector WhiteColor = FVector(FLinearColor::White.R, FLinearColor::White.G, FLinearColor::White.B);
	Cube->SetVectorParameterValueOnMaterials(FName(*MaterialInstanceColorParameterName), WhiteColor);

	GetWorldTimerManager().SetTimer(FlashTimerHandle, this, &ACube::OnFlashTimer, FlashSpeed, false);
}

void ACube::OnFlashTimer()
{
	GetWorldTimerManager().ClearTimer(FlashTimerHandle);
	Cube->SetVectorParameterValueOnMaterials(FName(*MaterialInstanceColorParameterName), Color);
}
