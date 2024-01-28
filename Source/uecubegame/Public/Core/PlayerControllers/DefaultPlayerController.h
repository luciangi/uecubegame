#pragma once

#include "InputAction.h"
#include "DefaultPlayerController.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()

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

public:
	/** Blueprint */
    virtual void BeginPlay() override;

private:
    void SetupInputBindings();
};
