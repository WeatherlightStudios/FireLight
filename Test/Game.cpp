#include "Game.h"



Game::Game()
{

}


void Game::Init()
{
	glClearColor(1,0,0,1);
	m_scene = std::make_unique<Test_Scene>();
	SceneManager::add_scene(m_scene.get(), "test");
	SceneManager::change_current_scene_to("test");

}

Game::~Game()
{
}
