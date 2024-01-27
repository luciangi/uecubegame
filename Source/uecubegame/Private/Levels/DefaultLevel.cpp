#include "Levels/DefaultLevel.h"

void ADefaultLevel::BeginPlay()
{
    Super::BeginPlay();

    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);

    StageTetracube(SpawnNewTetracube(CurrentTetracubeSpawnLocation));
}

void ADefaultLevel::HandleTetracubeCollisionEvent()
{
    CurrentTetracube->GetOnTetracubeCollision().RemoveDynamic(this, &ADefaultLevel::HandleTetracubeCollisionEvent);
    CurrentTetracube->Destroy();
    StageTetracube(NextTetracube);

    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);
}

ATetracube *ADefaultLevel::SpawnNewTetracube(FVector SpawnLocation)
{
    FTransform NewTetracubeTransform = FTransform::Identity;
    NewTetracubeTransform.SetLocation(SpawnLocation);
    ATetracube *NewTetracube = GetWorld()->SpawnActorDeferred<ATetracube>(TetracubeBlueprintClass, NewTetracubeTransform);

    if (NewTetracube)
    {
        NewTetracube->SetActorLocation(SpawnLocation);
        NewTetracube->SetDropSpeed(DropSpeed);
        NewTetracube->FinishSpawning(NewTetracubeTransform);
    }

    return NewTetracube;
}

void ADefaultLevel::StageTetracube(ATetracube *tetracube)
{
    tetracube->GetOnTetracubeCollision().AddDynamic(this, &ADefaultLevel::HandleTetracubeCollisionEvent);
    tetracube->SetActorLocation(CurrentTetracubeSpawnLocation);
    tetracube->StartDropping();

    CurrentTetracube = tetracube;
}
