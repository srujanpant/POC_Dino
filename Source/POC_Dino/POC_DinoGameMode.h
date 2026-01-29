// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "POC_DinoGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class APOC_DinoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	APOC_DinoGameMode();
};



