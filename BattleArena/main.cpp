#include <iostream>
#include <memory>
#include "Game.h"


int main()
{
	/*
	std::unique_ptr<Game> newGame(new Game);
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v1.0.0 alpha");
	newGame->Start();
	*/

	int* a;
	{
		std::unique_ptr<int> p = std::make_unique<int>(10);

		a = p.get();
	}

	std::cout << *a << std::endl;

	return 0;
}