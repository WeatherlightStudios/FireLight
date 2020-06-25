#include "Game.h"

int main()
{
	Game game;

	//game.Set_DEBUG_MODE();
	game.SetWindowDimension(1024, 768);
	game.SetWindowName("FireLight GameEngine v0.1.0 alpha");
	game.Start();

	system("PAUSE");

	return 0;
}