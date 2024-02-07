#pragma once

#include "InputAction.h"
#include "UI/Widgets/HudUserWidget.h"
#include "UI/Widgets/EndGameUserWidget.h"
#include "InputMappingContext.h"
#include "DefaultPlayerController.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADefaultPlayerController();

	/** Getters and Setters */
	int GetScore();
	int GetLevel();
	int GetClearedLines();

	void SetScore(int NewScore);
	void SetLevel(int NewLevel);
	void SetClearedLines(int NewClearedLines);

	/** Public */
	float ComputeDropSpeed();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Mappings")
	TSoftObjectPtr<UInputMappingContext> DefaultInputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeRotateAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeMoveLeftAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeMoveRightAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeMoveDownAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UHudUserWidget> HudWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UEndGameUserWidget> EndGameWidgetClass;

	virtual void BeginPlay() override;

private:
	UHudUserWidget *HudWidget;
	UEndGameUserWidget *EndGameWidget;

	int Score;
	int Level;
	int ClearedLines;

	void SetupInputBindings();
};
