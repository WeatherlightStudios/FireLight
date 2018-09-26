#include "Game.h"



Game::Game()
{

}


void Game::Init()
{
	glClearColor(1,0,0,1);
	m_scene = std::make_unique<Test_Scene>();
	SceneManager::AddScene(m_scene.get(), "test");
	SceneManager::changeCurrentSceneTo("test");

}

Game::~Game()
{
}
