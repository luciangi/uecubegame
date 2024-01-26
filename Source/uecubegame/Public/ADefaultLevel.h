#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "ATetracube.h"
#include "ADefaultLevel.generated.h"

UCLASS()
class UECUBEGAME_API ADefaultLevel : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ATetracube> TetracubeBlueprintClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector SpawnLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DropSpeed;

	virtual void BeginPlay() override;
};
