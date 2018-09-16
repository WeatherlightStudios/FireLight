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

	i = 0;
}


void Test_Scene::CameraUpdate(Camera *camera)
{
	speed = 100 * Time::GetDeltaTime();
	if (Window::isKeyDown(GLFW_KEY_W))
	{
		std::cout << "W" << std::endl;
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
	//std::cout << m_sprite->local_position().x << std::endl;
	
}

void Test_Scene::Update()
{

	//entity->getComponent<Sprite>()->m_offsetX = i;
	i++;

	if (i >= 6)
	{
		i = 0;
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
