#include "Game.h"


int main()
{
	std::unique_ptr<Game> newGame(new Game);
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v0.0.1 alpha");
	newGame->Start();
	return 0;
}