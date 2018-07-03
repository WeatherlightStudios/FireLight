#include "Test_Scene.h"
#include <math.h>
#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;


Test_Scene::Test_Scene()
{

}



void Test_Scene::Init()
{

	auto texture = Resource::LoadTexture("source/Texture/tilea2.png", true, "sprite");
	auto shader = Resource::LoadShader("source/Shaders/2D_shader.vert", "source/Shaders/2D_shader.frag", NULL, "2D_shader");

	m_sprite = new Sprite(texture, shader, 16, 12);

	m_sprite->set_position(glm::vec3(0, 0, 0));

	//m_sprite->set_local_scale(glm::vec3(1, 1, 1));
	m_sprite->set_rotation(0);

	add_object(*m_sprite);



	posX = 0;
	posY = 0;
	posZ = +3;

}


void Test_Scene::CameraUpdate(Camera *camera)
{
	speed = 100 * Time::GetDeltaTime();
	if (Window::isKeyDown(GLFW_KEY_W))
	{
		posY += speed;
	}

	if (Window::isKeyDown(GLFW_KEY_S))
	{
		posY -= speed;
	}

	if (Window::isKeyDown(GLFW_KEY_D))
	{
		posX += speed;
	}

	if (Window::isKeyDown(GLFW_KEY_A))
	{
		posX -= speed;
	}

	//Camera2D::rotate(1 * Time::GetDeltaTime());
	std::cout << m_sprite->local_position().x << std::endl;
	m_sprite->set_position(glm::vec3(posX, posY, 0.0f));
}

void Test_Scene::Update(double dt)
{

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
