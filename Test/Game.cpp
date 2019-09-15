#include "Game.h"



Game::Game()
{

}


void Game::Init()
{

	glClearColor((1/255.0) * 37.0, (1 / 255.0) * 137.0, (1 / 255.0) * 189.0,1);
	SceneManager::AddScene(std::make_unique<Test_Scene>(), "test");
	SceneManager::changeCurrentSceneTo("test");

}

Game::~Game()
{
}
