#include "UDefaultHudUserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/Overlay.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"

void UDefaultHudUserWidget::setTopValue(int top)
{
    TopValueText->SetText(FText::AsNumber(top));
}

void UDefaultHudUserWidget::setScoreValue(int score)
{
    ScoreValueText->SetText(FText::AsNumber(score));
}

void UDefaultHudUserWidget::setLevelValue(int level)
{
    LevelValueText->SetText(FText::AsNumber(level));
}
