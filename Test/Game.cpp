#include "Game.h"



Game::Game() : FL::App("Hello", 800,600), m_camera(glm::vec3(0,0,-3), glm::vec3(0,1,0), 90,0, projType::ORTHO)
{
	/*m_root = new SceneNode();
	obj1 = new SceneNode();
	obj2 = new SceneNode();
	obj1->set_local_position(glm::vec3(1, 0, 0));
	obj2->set_local_position(glm::vec3(1, 0, 0));*/

	m_testScene = new TestScene();
	SceneManager::add_scene(m_testScene, "testScene");
	SceneManager::set_current_scene("testScene");
}

void Game::Init()
{
	/*m_root->init();
	obj1->init();
	obj2->init();

	obj2->atuch_children(obj1);*/
}

void Game::Update(double deltaT)
{
	/*m_root->update(deltaT);
	m_camera.update();


	if (Window::isKeyDown(GLFW_KEY_W))
	{
		obj2->detuch_childern(obj1);
	}

	std::cout << m_root->get_renderables_Size() << std::endl;
	*/
}

void Game::Draw()
{

}

void Game::Close()
{

}


Game::~Game()
{

}
