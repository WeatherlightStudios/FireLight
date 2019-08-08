#include <iostream>
#include <memory>
#include "FlowerGame.h"


int main()
{
	std::unique_ptr<FlowerGame> newGame(new FlowerGame);
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v1.0.0 alpha");
	newGame->Start();

	return 0;
}