#include "UI/DefaultHudUserWidget.h"
#include "Components/TextBlock.h"

/** Public */
void UDefaultHudUserWidget::SetScore(int Score)
{
    ScoreValueText->SetText(FText::AsNumber(Score));
}

void UDefaultHudUserWidget::SetLevel(int Level)
{
    LevelValueText->SetText(FText::AsNumber(Level));
}
