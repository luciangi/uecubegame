// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "ADefaultLevel.generated.h"

/**
 *
 */
UCLASS()
class UECUBEGAME_API ADefaultLevel : public ALevelScriptActor
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
};
