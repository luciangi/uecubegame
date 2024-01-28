#include "UI/DefaultHud.h"
#include "UI/DefaultHudUserWidget.h"

/** Blueprint */
void ADefaultHud::DrawHUD()
{
    Super::DrawHUD();

    if (HudWidgetClass)
    {
        UDefaultHudUserWidget *WidgetInstance = CreateWidget<UDefaultHudUserWidget>(GetWorld(), HudWidgetClass);

        if (WidgetInstance)
        {
            WidgetInstance->AddToViewport();
        }
    }
}
