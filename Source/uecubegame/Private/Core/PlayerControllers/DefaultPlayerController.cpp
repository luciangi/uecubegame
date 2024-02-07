#include "Core/PlayerControllers/DefaultPlayerController.h"
#include "Core/GameModes/DefaultGameMode.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

ADefaultPlayerController::ADefaultPlayerController()
{
    Score = 0;
    Level = 0;
    ClearedLines = 0;
}

/** Getters and Setters */
int ADefaultPlayerController::GetScore()
{
    return Score;
}

int ADefaultPlayerController::GetLevel()
{
    return Level;
}

int ADefaultPlayerController::GetClearedLines()
{
    return ClearedLines;
}

void ADefaultPlayerController::SetScore(int NewScore)
{
    Score = NewScore;
    HudWidget->SetScore(Score);
}

void ADefaultPlayerController::SetLevel(int NewLevel)
{
    Level = NewLevel;
    HudWidget->SetLevel(Level);
}

void ADefaultPlayerController::SetClearedLines(int NewClearedLines)
{
    ClearedLines = NewClearedLines;
}

/** Public */
float ADefaultPlayerController::ComputeDropSpeed()
{
    const float DropSpeedIncrement = 0.1f;
    return FMath::Max(0.1f, 1.0f - (Level - 1) * DropSpeedIncrement);
}

/** Blueprint */
void ADefaultPlayerController::BeginPlay()
{
    Super::BeginPlay();

    HudWidget = CreateWidget<UHudUserWidget>(GetWorld(), HudWidgetClass);
    HudWidget->AddToViewport();
    HudWidget->SetScore(Score);
    HudWidget->SetLevel(Level);

    SetupInputBindings();
}

/** Private */
void ADefaultPlayerController::SetupInputBindings()
{
    ULocalPlayer *LocalPlayer = Cast<ULocalPlayer>(Player);
    UEnhancedInputLocalPlayerSubsystem *InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    InputSystem->AddMappingContext(DefaultInputMapping.LoadSynchronous(), 0);

    UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(InputComponent);
    ADefaultGameMode *DefaultGameMode = Cast<ADefaultGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    Input->BindAction(TetracubeRotateAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeRotate);
    Input->BindAction(TetracubeMoveLeftAction, ETriggerEvent::Triggered, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeMoveLeft);
    Input->BindAction(TetracubeMoveRightAction, ETriggerEvent::Triggered, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeMoveRight);
    Input->BindAction(TetracubeMoveDownAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeAccelerate);
    Input->BindAction(TetracubeMoveDownAction, ETriggerEvent::Completed, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeDecelerate);
}
