#include "Core/GameModes/DefaultGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

/** Public */
void ADefaultGameMode::PauseGame()
{
    AmbientSound->Stop();
    PlayerController->ShowPauseMenu();
    UGameplayStatics::SetGamePaused(GetGameInstance(), true);
}

void ADefaultGameMode::ResumeGame()
{
    AmbientSound->FadeIn(5.0f, 1.f);
    PlayerController->HidePauseMenu();
    UGameplayStatics::SetGamePaused(GetGameInstance(), false);
}

void ADefaultGameMode::ResetGame()
{
    RestartGame();
    PlayerController->ResetPlayerStats();
}

void ADefaultGameMode::OpenMainMenuLevel()
{
    UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), MainMenuLevel);
}

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

    AmbientSound->Play();
    PlayerController = Cast<ADefaultPlayerController>(GetWorld()->GetFirstPlayerController());
    StageTetracube(SpawnNewTetracube(CurrentTetracubeSpawnLocation));
    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);
}

void ADefaultGameMode::HandleTetracubeCollisionEvent()
{
    CurrentTetracube->GetOnTetracubeCollision().RemoveDynamic(this, &ADefaultGameMode::HandleTetracubeCollisionEvent);

    UClass *ActorClassFilter = ACube::StaticClass();

    bool IsEndGame = CheckLines->CheckOverlapWithEndLine(ActorClassFilter);
    if (IsEndGame)
    {
        AmbientSound->Stop();
        UGameplayStatics::PlaySound2D(GetWorld(), EndGameSound);
        PlayerController->ShowEndMenu();
        return;
    }

    TArray<float> CompletedLinesZLocation = CheckLines->CheckOverlapWithCompletedLines(ActorClassFilter);
    if (CompletedLinesZLocation.Num() > 0)
    {
        HandleCompletedLines(CompletedLinesZLocation);
    }

    StageTetracube(NextTetracube);
    NextTetracube = SpawnNewTetracube(NextTetracubeSpawnLocation);
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
        NewTetracube->FinishSpawning(NewTetracubeTransform);
    }

    return NewTetracube;
}

void ADefaultGameMode::StageTetracube(ATetracube *Tetracube)
{
    Tetracube->GetOnTetracubeCollision().AddDynamic(this, &ADefaultGameMode::HandleTetracubeCollisionEvent);
    Tetracube->SetActorLocation(CurrentTetracubeSpawnLocation);
    Tetracube->StartDropping(PlayerController->ComputeDropSpeed());

    CurrentTetracube = Tetracube;
}

void ADefaultGameMode::HandleCompletedLines(TArray<float> CompletedLinesZLocation)
{
    int CompletedLinesCount = CompletedLinesZLocation.Num();
    TArray<AActor *> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACube::StaticClass(), AllActors);

    for (float ZPosition : CompletedLinesZLocation)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), CompletedLineSound, FVector(0.f, 0.f, ZPosition));

        for (AActor *Actor : AllActors)
        {
            ACube *Cube = Cast<ACube>(Actor);
            float CubeZLocation = Cube->GetActorLocation().Z;

            if (CubeZLocation == ZPosition)
            {
                Cube->Remove();
            }
            else if (CubeZLocation > ZPosition)
            {
                Cube->DropTargetZLocation();
            }
        }
    }

    ComputeLevelAndScore(CompletedLinesCount);
}

void ADefaultGameMode::ComputeLevelAndScore(int ClearedLines)
{
    const int LinesToNextLevel = 5;

    int CurrentScore = PlayerController->GetScore();
    int CurrentLevel = PlayerController->GetLevel();
    int CurrentClearedLines = PlayerController->GetClearedLines();

    PlayerController->SetScore(CurrentScore + (CurrentLevel + 1) * ClearedLines * 100);

    if (CurrentClearedLines >= LinesToNextLevel)
    {
        PlayerController->SetLevel(CurrentLevel + 1);
        PlayerController->SetClearedLines(0);
    }
    else
    {
        PlayerController->SetClearedLines(CurrentClearedLines + ClearedLines);
    }
}
