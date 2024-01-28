#include "Core/PlayerControllers/DefaultPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Core/GameModes/DefaultGameMode.h"
#include "Kismet/GameplayStatics.h"

/** Blueprint */
void ADefaultPlayerController::BeginPlay()
{
    Super::BeginPlay();

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
