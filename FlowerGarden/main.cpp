#include "FlowerGame.h"
#include <memory>
#include <Windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
	std::unique_ptr<FlowerGame> newGame(new FlowerGame);
	newGame->Set_DEBUG_MODE(true);
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v1.0.0 alpha");
	newGame->Start();

	return 0;
}