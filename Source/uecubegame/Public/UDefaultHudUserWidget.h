#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UDefaultHudUserWidget.generated.h"

class UTextBlock;

UCLASS()
class UECUBEGAME_API UDefaultHudUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void setTopValue(int top);
	void setScoreValue(int score);
	void setLevelValue(int level);

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TopValueText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreValueText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* LevelValueText;
};
