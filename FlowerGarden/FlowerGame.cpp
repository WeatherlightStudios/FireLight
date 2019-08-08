#include "FlowerGame.h"

FlowerGame::FlowerGame()
{

}

void FlowerGame::Init()
{
	#define BG_COLOR(r,g,b) glClearColor((1.0 / 255.0) * r##.0, (1.0 / 255.0) * g##.0, (1 / 255.0) * b##.0, 1)
	
	BG_COLOR(249, 154, 52);
	m_scene = std::make_unique<MainGameScene>();
	SceneManager::AddScene(m_scene.get(), "Game");
	SceneManager::changeCurrentSceneTo("Game");
	
}

FlowerGame::~FlowerGame()
{

}
