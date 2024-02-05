#pragma once

#include "GameFramework/GameMode.h"
#include "Engine/LevelScriptActor.h"
#include "InputMappingContext.h"
#include "Actors/Tetracube.h"
#include "Actors/CheckLines.h"
#include "DefaultGameMode.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	void CurrentTetracubeRotate();
	void CurrentTetracubeMoveLeft();
	void CurrentTetracubeMoveRight();
	void CurrentTetracubeAccelerate();
	void CurrentTetracubeDecelerate();

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	TSubclassOf<ATetracube> TetracubeBlueprintClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	FVector CurrentTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	FVector NextTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	float TetracubeDropSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tetracube")
	TSoftObjectPtr<ACheckLines> CheckLines;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleTetracubeCollisionEvent();

private:
	ATetracube *CurrentTetracube;
	ATetracube *NextTetracube;

	ATetracube *SpawnNewTetracube(FVector SpawnLocation);
	void StageTetracube(ATetracube *Tetracube);
};
