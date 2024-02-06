#include "UI/DefaultHudUserWidget.h"
#include "Components/TextBlock.h"

/** Public */
void UDefaultHudUserWidget::SetScoreAndLevel(int Score, int Level)
{
    ScoreValueText->SetText(FText::AsNumber(Score));
    LevelValueText->SetText(FText::AsNumber(Level));
}
