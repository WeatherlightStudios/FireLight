#include <iostream>
#include <memory>
#include "Game.h"

using namespace std;

int main()
{

	//TODO: da spostare nell heap e usare uno smart pointer
	//TEST
	std::unique_ptr<Game> m_game(new Game);
	m_game->set_window_dimension(800, 600);
	m_game->set_windiw_name("FireLight engine v1.0.0");
	m_game->start();

	return 0;
}