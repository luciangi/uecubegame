#pragma once

#include "GameFramework/HUD.h"
#include "DefaultHudUserWidget.h"
#include "DefaultHud.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultHud : public AHUD
{
	GENERATED_BODY()

public:
	/** Blueprint */
	virtual void DrawHUD() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UDefaultHudUserWidget> HudWidgetClass;
};
