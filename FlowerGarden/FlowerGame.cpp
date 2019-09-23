#include "FlowerGame.h"

FlowerGame::FlowerGame()
{

}

void FlowerGame::Init()
{
	BG_COLOR(249, 154, 52);
	SceneManager::AddScene(std::make_unique<MainGameScene>(), "Game");
	SceneManager::changeCurrentSceneTo("Game");
}

FlowerGame::~FlowerGame()
{

}
