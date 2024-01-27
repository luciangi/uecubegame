#pragma once

#include "Engine/LevelScriptActor.h"
#include "Actors/Tetracube.h"
#include "DefaultLevel.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultLevel : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ATetracube> TetracubeBlueprintClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector CurrentTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector NextTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropSpeed;

	virtual void BeginPlay() override;

private:
	ATetracube *CurrentTetracube;
	ATetracube *NextTetracube;

	UFUNCTION()
	void HandleTetracubeCollisionEvent();

	ATetracube *SpawnNewTetracube(FVector SpawnLocation);
	void StageTetracube(ATetracube *tetracube);
};
