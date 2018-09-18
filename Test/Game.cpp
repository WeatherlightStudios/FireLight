#include "Game.h"



Game::Game()
{

}


void Game::Init()
{
	glClearColor(1,0,0,1);

	SceneManager::add_scene(&m_scene, "test");
	SceneManager::change_current_scene_to("test");

}

Game::~Game()
{
}
