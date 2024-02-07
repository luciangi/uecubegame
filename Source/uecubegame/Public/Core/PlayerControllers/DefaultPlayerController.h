#pragma once

#include "InputAction.h"
#include "UI/DefaultHudUserWidget.h"
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
	TSubclassOf<UDefaultHudUserWidget> HudWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UDefaultHudUserWidget> EndGameWidgetClass;

	virtual void BeginPlay() override;

private:
	UDefaultHudUserWidget *HudWidget;
	UDefaultHudUserWidget *EndGameWidget;

	int Score;
	int Level;
	int ClearedLines;

	void SetupInputBindings();
};
