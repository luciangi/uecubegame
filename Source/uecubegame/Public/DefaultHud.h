#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DefaultHud.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultHud : public AHUD
{
	GENERATED_BODY()

public:
	ADefaultHud();

	virtual void DrawHUD() override;

private:
	class UDefaultHudUserWidget *HudWidget;
};
