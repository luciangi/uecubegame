#include "UI/DefaultHudUserWidget.h"
#include "Components/TextBlock.h"

/** Getters and Setters */
void UDefaultHudUserWidget::SetScoreValue(int NewScore)
{
    ScoreValueText->SetText(FText::AsNumber(NewScore));
}

void UDefaultHudUserWidget::SetLevelValue(int NewLevel)
{
    LevelValueText->SetText(FText::AsNumber(NewLevel));
}
