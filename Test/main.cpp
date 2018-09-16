#include <iostream>
#include <memory>
#include "Game.h"

using namespace std;

int main()
{


	std::unique_ptr<Game> m_game(new Game);
	m_game->set_window_dimension(800, 600);
	m_game->set_windiw_name("FireLight engine v0.0.1");
	m_game->start();

	return 0;
}