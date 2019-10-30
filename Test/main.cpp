#include "Game.h"
//#include <Windows.h>

//int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
int main()
{
	std::unique_ptr<Game> newGame(new Game);
	newGame->Set_DEBUG_MODE();
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight GameEngine v1.0.0 alpha");
	newGame->Start();
	return 0;
}