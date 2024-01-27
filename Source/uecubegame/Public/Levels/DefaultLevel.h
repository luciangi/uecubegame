#pragma once

#include "Engine/LevelScriptActor.h"
#include "Actors/Tetracube.h"
#include "DefaultLevel.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultLevel : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	/** Blueprint */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ATetracube> TetracubeBlueprintClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector CurrentTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector NextTetracubeSpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropSpeed;

	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleTetracubeCollisionEvent();

private:
	ATetracube *CurrentTetracube;
	ATetracube *NextTetracube;

	ATetracube *SpawnNewTetracube(FVector SpawnLocation);
	void StageTetracube(ATetracube *Tetracube);
};
