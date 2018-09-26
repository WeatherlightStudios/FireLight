#include <iostream>
#include <memory>
#include "Game.h"	

using namespace std;

int main()
{


	std::unique_ptr<Game> m_game(new Game);
	m_game->setWindowDimension(800, 600);
	m_game->setWindowName("FireLight engine v0.0.1");
	m_game->Start();

	return 0;
}