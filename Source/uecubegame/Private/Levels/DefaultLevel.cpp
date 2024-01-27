#include "Levels/DefaultLevel.h"

/** Blueprint */
void ADefaultLevel::BeginPlay()
{
    Super::BeginPlay();

    StageTetracube(SpawnNewTetracube(CurrentTetracubeSpawnLocation));
    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);
}

void ADefaultLevel::HandleTetracubeCollisionEvent()
{
    CurrentTetracube->GetOnTetracubeCollision().RemoveDynamic(this, &ADefaultLevel::HandleTetracubeCollisionEvent);

    StageTetracube(NextTetracube);
    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);
}

/** Private */
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

void ADefaultLevel::StageTetracube(ATetracube *Tetracube)
{
    Tetracube->GetOnTetracubeCollision().AddDynamic(this, &ADefaultLevel::HandleTetracubeCollisionEvent);
    Tetracube->SetActorLocation(CurrentTetracubeSpawnLocation);
    Tetracube->StartDropping();

    CurrentTetracube = Tetracube;
}
