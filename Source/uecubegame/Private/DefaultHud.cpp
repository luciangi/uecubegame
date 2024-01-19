#include "DefaultHud.h"
#include "UDefaultHudUserWidget.h"

ADefaultHud::ADefaultHud()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> HudWidgetClassFinder(TEXT("/Game/Blueprints/B_HudUserWidget"));
    if (HudWidgetClassFinder.Succeeded())
    {
        HudWidget = CreateWidget<UDefaultHudUserWidget>(GetWorld(), HudWidgetClassFinder.Class);
    }
}

void ADefaultHud::DrawHUD()
{
    Super::DrawHUD();

    if (HudWidget)
    {
        HudWidget->AddToViewport();
    }
}
