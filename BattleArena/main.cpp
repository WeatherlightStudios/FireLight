#include <iostream>
#include <memory>
#include "Game.h"


int main()
{

	std::unique_ptr<Game> newGame(new Game);
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v1.0.0 alpha");
	newGame->Start();

	return 0;
}