#pragma once

#include "InputAction.h"
#include "UI/DefaultHud.h"
#include "DefaultPlayerController.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ADefaultPlayerController();

	/** Getters and Setters */
	float GetTetracubeDropSpeed();

	/** Public */
	void ComputeLevelAndScore(int ClearedLines);

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	UInputAction *RotateAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	UInputAction *MoveLeftAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	UInputAction *MoveRightAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	UInputAction *MoveDownAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hud")
	TSubclassOf<ADefaultHud> HudClass;

	virtual void BeginPlay() override;

private:
	ADefaultHud *Hud;

	int Score;
	int Level;
	int ClearedLines;
	float TetracubeDropSpeed;

	void SetupInputBindings();
    void UpdateHud();
};
