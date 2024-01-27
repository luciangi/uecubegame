#pragma once

#include "GameFramework/HUD.h"
#include "DefaultHud.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultHud : public AHUD
{
	GENERATED_BODY()

public:
	/** Constructors */
	ADefaultHud();

	/** Blueprint */
	virtual void DrawHUD() override;

private:
	class UDefaultHudUserWidget *HudWidget;
};