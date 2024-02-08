#pragma once

#include "GameFramework/GameMode.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuGameMode.generated.h"

UCLASS()
class UECUBEGAME_API AMainMenuGameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Levels")
	TSoftObjectPtr<UWorld> DefaultLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OpenDefaultLevel();

private:
	UUserWidget *MainMenuWidget;
};
