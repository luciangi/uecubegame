#include "UI/DefaultHud.h"
#include "UI/DefaultHudUserWidget.h"

/** Public */
void ADefaultHud::SetScoreAndLevel(int Score, int Level)
{
    WidgetInstance->SetScoreAndLevel(Score, Level);
}

/** Blueprint */
void ADefaultHud::OnConstruction(const FTransform &Transform)
{
    Super::OnConstruction(Transform);

    WidgetInstance = CreateWidget<UDefaultHudUserWidget>(GetWorld(), HudWidgetClass);
    WidgetInstance->AddToViewport();
}
