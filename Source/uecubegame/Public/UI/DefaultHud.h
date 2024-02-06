#pragma once

#include "GameFramework/HUD.h"
#include "DefaultHudUserWidget.h"
#include "DefaultHud.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultHud : public AHUD
{
	GENERATED_BODY()

public:
	/** Public */
    void SetScoreAndLevel(int Score, int Level);

    /** Blueprint */
    virtual void OnConstruction(const FTransform &Transform) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UDefaultHudUserWidget> HudWidgetClass;

private:
	UDefaultHudUserWidget *WidgetInstance;
};
