#include "Core/GameModes/MainMenuGameMode.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuGameMode::BeginPlay()
{
    Super::BeginPlay();

    MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);
    MainMenuWidget->AddToViewport();

    APlayerController *PlayerController = GetWorld()->GetFirstPlayerController();
    FInputModeUIOnly InputMode;
    PlayerController->SetInputMode(InputMode);
    PlayerController->bShowMouseCursor = true;
}

/** Public */
void AMainMenuGameMode::OpenDefaultLevel()
{
    UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), DefaultLevel);
}
