#include "Game.h"



Game::Game()
{

}

void Game::Init()
{
	BG_COLOR(37, 137, 189);

	m_scene = std::make_unique<GameScene>();
	SceneManager::AddScene(m_scene.get(), "Game");
	SceneManager::changeCurrentSceneTo("Game");
}

Game::~Game()
{

}
