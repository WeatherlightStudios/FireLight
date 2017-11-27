#include "Game.h"



Game::Game() : FL::App("Hello", 800,600) //m_camera(glm::vec3(0,0,-3), glm::vec3(0,1,0), 90,0, projType::ORTHO)
{
	/*m_root = new SceneNode();
	obj1 = new SceneNode();
	obj2 = new SceneNode();
	obj1->set_local_position(glm::vec3(1, 0, 0));
	obj2->set_local_position(glm::vec3(1, 0, 0));*/
	//SimpleRenderSystem::set_Camera(&m_camera);
}

void Game::Init()
{
	ResourceManager::LoadShader("shader.vert","shader.frag", nullptr, "shader");
	SceneManager::add_scene(&m_testScene, "testScene");
	SceneManager::set_current_scene("testScene");
	//SceneManager::init_current_scene();
	/*m_root->init();
	obj1->init();
	obj2->init();

	obj2->atuch_children(obj1);*/
}

Game::~Game()
{

}
