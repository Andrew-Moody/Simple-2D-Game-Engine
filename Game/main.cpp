#include <SDL.h>
#include <iostream>
#include <string>

#include <fstream>
#include <vector>

#include "../Engine/Core/enginecore.h"

#include "Components/usercomponentregistry.h"
#include "Data/Levels/userlevelregistry.h"

int main( int argc, char* args[])
{

	//Create a engineCore
	std::unique_ptr<EngineCore> gameCore = std::make_unique<EngineCore>();
	
	// Perform initialization of core systems
	gameCore->setupCore("Game/Data/window.txt");
	
	// Load game
	gameCore->loadGame("Game/Data/game.txt", User::RegisterUserComponents, User::RegisterUserLevels);

	// Game loop
	bool done = false;
	while (!done)
	{
		done = gameCore->run();
	}

	return 0;
}