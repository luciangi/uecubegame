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

void ADefaultPlayerController::PauseGame()
{
    RemoveInputMapping(GameInputMapping);
    AddInputMapping(PausedInputMapping);
    if (!PausedGameWidget)
    {
        PausedGameWidget = CreateWidget<UUserWidget>(GetWorld(), PausedGameWidgetClass);
    }
    PausedGameWidget->AddToViewport();
}

void ADefaultPlayerController::ResumeGame()
{
    RemoveInputMapping(PausedInputMapping);
    AddInputMapping(GameInputMapping);
    PausedGameWidget->RemoveFromParent();
}

void ADefaultPlayerController::EndGame()
{
    RemoveInputMapping(GameInputMapping);
    if (!EndGameWidget)
    {
        EndGameWidget = CreateWidget<UUserWidget>(GetWorld(), EndGameWidgetClass);
    }
    EndGameWidget->AddToViewport();
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
    AddInputMapping(GameInputMapping);
}

/** Private */
void ADefaultPlayerController::SetupInputBindings()
{
    UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(InputComponent);
    ADefaultGameMode *DefaultGameMode = Cast<ADefaultGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

    Input->BindAction(PauseGameAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::PauseGame);
    Input->BindAction(ResumeGameAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::ResumeGame);

    Input->BindAction(TetracubeRotateAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeRotate);
    Input->BindAction(TetracubeMoveLeftAction, ETriggerEvent::Triggered, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeMoveLeft);
    Input->BindAction(TetracubeMoveRightAction, ETriggerEvent::Triggered, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeMoveRight);
    Input->BindAction(TetracubeMoveDownAction, ETriggerEvent::Started, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeAccelerate);
    Input->BindAction(TetracubeMoveDownAction, ETriggerEvent::Completed, DefaultGameMode, &ADefaultGameMode::CurrentTetracubeDecelerate);
}

void ADefaultPlayerController::AddInputMapping(TSoftObjectPtr<UInputMappingContext> MappingContext)
{
    UEnhancedInputLocalPlayerSubsystem *InputSystem = Cast<ULocalPlayer>(Player)->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    InputSystem->AddMappingContext(MappingContext.LoadSynchronous(), 0);
}

void ADefaultPlayerController::RemoveInputMapping(TSoftObjectPtr<UInputMappingContext> MappingContext)
{
    UEnhancedInputLocalPlayerSubsystem *InputSystem = Cast<ULocalPlayer>(Player)->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    InputSystem->RemoveMappingContext(MappingContext.LoadSynchronous());
}
