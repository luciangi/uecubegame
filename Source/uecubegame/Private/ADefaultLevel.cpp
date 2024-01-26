#include "ADefaultLevel.h"

void ADefaultLevel::BeginPlay()
{
    Super::BeginPlay();

    ATetracube::SpawnNewTetracube(GetWorld(), TetracubeBlueprintClass, SpawnLocation, DropSpeed);
}
