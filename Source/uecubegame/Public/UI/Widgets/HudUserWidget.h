#pragma once

#include "Blueprint/UserWidget.h"
#include "HudUserWidget.generated.h"

class UTextBlock;

UCLASS()
class UECUBEGAME_API UHudUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Public */
	void SetScore(int Score);
	void SetLevel(int Level);

private:
	/** Blueprint */
	UPROPERTY(meta = (BindWidget))
	UTextBlock *ScoreValueText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock *LevelValueText;
};
