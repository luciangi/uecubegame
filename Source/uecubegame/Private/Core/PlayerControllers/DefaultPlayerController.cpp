#include "Core/PlayerControllers/DefaultPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Core/GameModes/DefaultGameMode.h"
#include "Kismet/GameplayStatics.h"

ADefaultPlayerController::ADefaultPlayerController()
{
    Score = 0;
    Level = 0;
    TetracubeDropSpeed = 1;
}

/** Getters and Setters */
float ADefaultPlayerController::GetTetracubeDropSpeed()
{
    return TetracubeDropSpeed;
}

/** Public */
void ADefaultPlayerController::ComputeLevelAndScore(int CurrentClearedLines)
{
    const int LinesToNextLevel = 10;
    const float TetracubeDropSpeedIncrement = 0.1f;

    Score += (Level + 1) * CurrentClearedLines * 100;

    ClearedLines += CurrentClearedLines;

    if (ClearedLines >= LinesToNextLevel)
    {
        Level++;
        ClearedLines = 0;

        if (TetracubeDropSpeed > TetracubeDropSpeedIncrement)
        {
            TetracubeDropSpeed -= TetracubeDropSpeedIncrement;
        }
    }

    UpdateHud();
}

/** Blueprint */
void ADefaultPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ClientSetHUD(HudClass);
    UpdateHud();
    SetupInputBindings();
}

/** Private */
void ADefaultPlayerController::SetupInputBindings()
{

    UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(InputComponent);

    ADefaultGameMode *DefaultGameMode = Cast<ADefaultGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    Input->BindAction(RotateAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeRotate);
    Input->BindAction(MoveLeftAction, ETriggerEvent::Triggered, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeMoveLeft);
    Input->BindAction(MoveRightAction, ETriggerEvent::Triggered, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeMoveRight);
    Input->BindAction(MoveDownAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeAccelerate);
    Input->BindAction(MoveDownAction, ETriggerEvent::Completed, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeDecelerate);
}

void ADefaultPlayerController::UpdateHud()
{
    GetHUD<ADefaultHud>()->SetScoreAndLevel(Score, Level);
}
