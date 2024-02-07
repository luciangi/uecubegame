#include "UI/Widgets/HudUserWidget.h"
#include "Components/TextBlock.h"

/** Public */
void UHudUserWidget::SetScore(int Score)
{
    ScoreValueText->SetText(FText::AsNumber(Score));
}

void UHudUserWidget::SetLevel(int Level)
{
    LevelValueText->SetText(FText::AsNumber(Level));
}
