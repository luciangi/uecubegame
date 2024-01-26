#include "UDefaultHudUserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/Overlay.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"

void UDefaultHudUserWidget::SetTopValue(int NewTop)
{
    TopValueText->SetText(FText::AsNumber(NewTop));
}

void UDefaultHudUserWidget::SetScoreValue(int NewScore)
{
    ScoreValueText->SetText(FText::AsNumber(NewScore));
}

void UDefaultHudUserWidget::SetLevelValue(int NewLevel)
{
    LevelValueText->SetText(FText::AsNumber(NewLevel));
}
