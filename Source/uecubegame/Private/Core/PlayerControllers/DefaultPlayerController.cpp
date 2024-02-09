#include "Core/PlayerControllers/DefaultPlayerController.h"
#include "Core/GameModes/DefaultGameMode.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

ADefaultPlayerController::ADefaultPlayerController()
{
    ResetPlayerStats();
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
void ADefaultPlayerController::ShowPauseMenu()
{
    if (!PausedGameWidget)
    {
        PausedGameWidget = CreateWidget<UUserWidget>(GetWorld(), PausedGameWidgetClass);
    }

    AddInputMapping(PausedInputMapping);
    ShowWidget(PausedGameWidget);
}

void ADefaultPlayerController::HidePauseMenu()
{
    RemoveInputMapping(PausedInputMapping);
    HideWidget(PausedGameWidget);
}

void ADefaultPlayerController::ShowEndMenu()
{
    if (!EndGameWidget)
    {
        EndGameWidget = CreateWidget<UUserWidget>(GetWorld(), EndGameWidgetClass);
    }

    ShowWidget(EndGameWidget);
}

void ADefaultPlayerController::HideEndMenu()
{
    HideWidget(EndGameWidget);
}

void ADefaultPlayerController::ResetPlayerStats()
{
    Score = 0;
    Level = 0;
    ClearedLines = 0;
}

float ADefaultPlayerController::ComputeDropSpeed()
{
    const float DropSpeedIncrement = 0.2f;
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

    SetGameInputMode();
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

void ADefaultPlayerController::ShowWidget(UUserWidget *Widget)
{
    RemoveInputMapping(GameInputMapping);
    SetMenuInputMode();

    Widget->AddToViewport();
}

void ADefaultPlayerController::HideWidget(UUserWidget *Widget)
{
    AddInputMapping(GameInputMapping);
    SetGameInputMode();

    Widget->RemoveFromParent();
}

void ADefaultPlayerController::SetMenuInputMode()
{
    FInputModeGameAndUI InputMode;
    SetInputMode(InputMode);
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    bShowMouseCursor = true;
}

void ADefaultPlayerController::SetGameInputMode()
{
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
    bShowMouseCursor = false;
}
