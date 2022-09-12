// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ValeGameState.generated.h"

/**
 * 
 */
UCLASS()
class DES365_PROJECTONE_API AValeGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		bool bGamePaused = false;

	

	
};
