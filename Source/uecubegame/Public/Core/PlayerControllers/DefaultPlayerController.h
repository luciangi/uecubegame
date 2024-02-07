#pragma once

#include "InputAction.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widgets/HudUserWidget.h"
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
	void PauseGame();
	void ResumeGame();
	void EndGame();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Mappings")
	TSoftObjectPtr<UInputMappingContext> GameInputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Mappings")
	TSoftObjectPtr<UInputMappingContext> PausedInputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *PauseGameAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *ResumeGameAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeRotateAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeMoveLeftAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeMoveRightAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input Actions")
	UInputAction *TetracubeMoveDownAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> HudWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> PausedGameWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> EndGameWidgetClass;

	virtual void BeginPlay() override;

private:
	UHudUserWidget *HudWidget;
	UUserWidget *PausedGameWidget;
	UUserWidget *EndGameWidget;

	int Score;
	int Level;
	int ClearedLines;

	void SetupInputBindings();
	void AddInputMapping(TSoftObjectPtr<UInputMappingContext> MappingContext);
	void RemoveInputMapping(TSoftObjectPtr<UInputMappingContext> MappingContext);
};
