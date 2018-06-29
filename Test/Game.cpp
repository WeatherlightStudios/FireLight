#include "Game.h"



Game::Game() : App("FireLight Engine", 800,600)
{

}


void Game::Init()
{
	glClearColor(0,0,0,1);

	SceneManager::add_scene(&m_scene, "test");
	SceneManager::change_current_scene_to("test");

}

Game::~Game()
{
}
