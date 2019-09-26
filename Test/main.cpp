#include "Game.h"
#include <Windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
	auto newGame = Game();
	newGame.Set_DEBUG_MODE(true);
	newGame.SetWindowDimension(800, 600);
	newGame.SetWindowName("FireLight engine v0.0.1 alpha");
	newGame.Start();
	return 0;
}