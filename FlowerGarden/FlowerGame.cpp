#include "FlowerGame.h"

FlowerGame::FlowerGame()
{

}

void FlowerGame::Init()
{
	BG_COLOR(249, 154, 52);
	m_scene = std::make_unique<MainGameScene>();
	SceneManager::AddScene(m_scene.get(), "Game");
	SceneManager::changeCurrentSceneTo("Game");
}

FlowerGame::~FlowerGame()
{

}
