// Copyright Epic Games, Inc. All Rights Reserved.

#include "ch2Assignment6GameMode.h"
#include "ch2Assignment6Character.h"
#include "UObject/ConstructorHelpers.h"

Ach2Assignment6GameMode::Ach2Assignment6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
