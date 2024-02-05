#include "Core/GameModes/DefaultGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"

/** Public */
void ADefaultGameMode::CurrentTetracubeRotate()
{
    CurrentTetracube->Rotate();
}

void ADefaultGameMode::CurrentTetracubeMoveLeft()
{
    CurrentTetracube->MoveLeft();
}

void ADefaultGameMode::CurrentTetracubeMoveRight()
{
    CurrentTetracube->MoveRight();
}

void ADefaultGameMode::CurrentTetracubeAccelerate()
{
    CurrentTetracube->Accelerate();
}

void ADefaultGameMode::CurrentTetracubeDecelerate()
{
    CurrentTetracube->Decelerate();
}

/** Blueprint */
void ADefaultGameMode::BeginPlay()
{
    Super::BeginPlay();

    ULocalPlayer *LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();

    if (UEnhancedInputLocalPlayerSubsystem *InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
    {
        if (!InputMapping.IsNull())
        {
            InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
        }
    }

    StageTetracube(SpawnNewTetracube(CurrentTetracubeSpawnLocation));
    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);
}

void ADefaultGameMode::HandleTetracubeCollisionEvent()
{
    CurrentTetracube->GetOnTetracubeCollision().RemoveDynamic(this, &ADefaultGameMode::HandleTetracubeCollisionEvent);

    StageTetracube(NextTetracube);
    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);

    TArray<float> CompletedLineZLocation = CheckLines->CheckCompletedLines(ACube::StaticClass());

    if (CompletedLineZLocation.Num() > 0)
    {
        TMap<AActor *, float> ActorsToTargetZLocation;
        TArray<AActor *> AllActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACube::StaticClass(), AllActors);

        for (AActor *Actor : AllActors)
        {
            ACube *Cube = Cast<ACube>(Actor);
            float CubeZLocation = Cube->GetActorLocation().Z;

            for (float ZPosition : CompletedLineZLocation)
            {
                if (CubeZLocation == ZPosition)
                {
                    Cube->Destroy();
                }
                else if (CubeZLocation > ZPosition)
                {
                    if (!ActorsToTargetZLocation.Contains(Actor))
                    {
                        ActorsToTargetZLocation.Add(Actor, CubeZLocation);
                    }

                    float TargetZLocation = *ActorsToTargetZLocation.Find(Actor);
                    TargetZLocation -= CubeSize;
                    ActorsToTargetZLocation.Add(Actor, TargetZLocation);
                }
            }
        }

        for (const auto &KeyValue : ActorsToTargetZLocation)
        {
            ACube *Cube = Cast<ACube>(KeyValue.Key);
            float TargetZLocation = KeyValue.Value;

            Cube->SetZLocation(TargetZLocation);
        }
    }
}

/** Private */
ATetracube *ADefaultGameMode::SpawnNewTetracube(FVector SpawnLocation)
{
    FTransform NewTetracubeTransform = FTransform::Identity;
    NewTetracubeTransform.SetLocation(SpawnLocation);
    ATetracube *NewTetracube = GetWorld()->SpawnActorDeferred<ATetracube>(TetracubeBlueprintClass, NewTetracubeTransform);

    if (NewTetracube)
    {
        NewTetracube->SetActorLocation(SpawnLocation);
        NewTetracube->SetDropSpeed(TetracubeDropSpeed);
        NewTetracube->FinishSpawning(NewTetracubeTransform);
    }

    return NewTetracube;
}

void ADefaultGameMode::StageTetracube(ATetracube *Tetracube)
{
    Tetracube->GetOnTetracubeCollision().AddDynamic(this, &ADefaultGameMode::HandleTetracubeCollisionEvent);
    Tetracube->SetActorLocation(CurrentTetracubeSpawnLocation);
    Tetracube->StartDropping();

    CurrentTetracube = Tetracube;
}
