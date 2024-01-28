#pragma once

#include "Blueprint/UserWidget.h"
#include "DefaultHudUserWidget.generated.h"

class UTextBlock;

UCLASS()
class UECUBEGAME_API UDefaultHudUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Getters and Setters */
	void SetScoreValue(int NewScore);
	void SetLevelValue(int NewLevel);

private:
	/** Blueprint */
	UPROPERTY(meta = (BindWidget))
	UTextBlock *ScoreValueText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock *LevelValueText;
};
