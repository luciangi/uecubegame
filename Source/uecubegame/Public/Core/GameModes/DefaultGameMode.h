#pragma once

#include "GameFramework/GameMode.h"
#include "Engine/LevelScriptActor.h"
#include "Core/Actors/Tetracube.h"
#include "Core/Actors/CheckLines.h"
#include "Core/PlayerControllers/DefaultPlayerController.h"
#include "DefaultGameMode.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	void PauseGame();
	UFUNCTION(BlueprintCallable)
	void ResumeGame();
	UFUNCTION(BlueprintCallable)
	void ResetGame();
	UFUNCTION(BlueprintCallable)
	void OpenMainMenuLevel();

	void CurrentTetracubeRotate();
	void CurrentTetracubeMoveLeft();
	void CurrentTetracubeMoveRight();
	void CurrentTetracubeAccelerate();
	void CurrentTetracubeDecelerate();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Levels")
	TSoftObjectPtr<UWorld> MainMenuLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	TSubclassOf<ATetracube> TetracubeBlueprintClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	FVector CurrentTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	FVector NextTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	TSoftObjectPtr<ACheckLines> CheckLines;

	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleTetracubeCollisionEvent();

private:
	ATetracube *CurrentTetracube;
	ATetracube *NextTetracube;

	ADefaultPlayerController *PlayerController;

	ATetracube *SpawnNewTetracube(FVector SpawnLocation);
	void StageTetracube(ATetracube *Tetracube);
	void HandleCompletedLines(TArray<float> CompletedLinesZLocation);
	void ComputeLevelAndScore(int CurrentClearedLines);
};
