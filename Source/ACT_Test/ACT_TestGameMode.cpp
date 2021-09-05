// Copyright Epic Games, Inc. All Rights Reserved.

#include "ACT_TestGameMode.h"
#include "ACT_TestPlayerController.h"
#include "ACT_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AACT_TestGameMode::AACT_TestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AACT_TestPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}