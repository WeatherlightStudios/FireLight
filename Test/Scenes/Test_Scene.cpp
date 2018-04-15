#include "Test_Scene.h"
#include <math.h>


Test_Scene::Test_Scene()
{
}



void Test_Scene::Init()
{
	ResourceManager::LoadTexture("source/Texture/tilea2.png", true, "tile1");
	ResourceManager::LoadShader("source/Shaders/shader.vert", "source/Shaders/shader.frag", NULL, "shader");
	m_sprite = new Renderable();

	m_sprite->setName("Obj1");

	m_sprite->set_texture("tile1");

	m_sprite->set_local_position(glm::vec3(0,0,0));
	m_sprite->set_local_scale(glm::vec3(1, 1, 1));
	m_sprite->set_local_rotation(0);

	m_sprite->set_texture_row(glm::vec2(16,8));
	m_sprite->set_texture_offset(glm::vec2(0, 0));
	add_object(m_sprite);
}


void Test_Scene::CameraUpdate(Camera *camera)
{

}

void Test_Scene::Update(double dt)
{
	t++;


	//m_sprite->set_local_rotation(t / 30.0f);


	if (Window::isKeyDown(GLFW_KEY_E))
	{

		this->remove_object(m_sprite);
		//delete(m_sprite);
	}
}

void Test_Scene::Debughing(Debug *debug)
{

}

void Test_Scene::Close()
{

}


Test_Scene::~Test_Scene()
{

}
