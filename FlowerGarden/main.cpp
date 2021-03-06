#include "FlowerGame.h"
#include <memory>

///int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
int main()
{
	//std::unique_ptr<FlowerGame> newGame(new FlowerGame);
	auto newGame = std::make_unique<FlowerGame>();
	newGame->Set_DEBUG_MODE(true);
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight engine v1.0.0 alpha");
	newGame->Start();

	return 0;
}