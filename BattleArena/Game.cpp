#include "Game.h"



Game::Game()
{

}

void Game::Init()
{
	glClearColor((1 / 255.0) * 37.0, (1 / 255.0) * 137.0, (1 / 255.0) * 189.0, 1);

	m_scene = std::make_unique<GameScene>();
	SceneManager::AddScene(m_scene.get(), "Game");
	SceneManager::changeCurrentSceneTo("Game");
}

Game::~Game()
{

}
