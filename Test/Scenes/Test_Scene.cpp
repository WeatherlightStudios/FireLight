#include "Test_Scene.h"
#include <math.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "TestSystem.h"
using namespace std;


Test_Scene::Test_Scene()
{

}




void Test_Scene::Init()
{

	auto texture = Resource::LoadTexture("source/Texture/Front.png", true, "sprite");
	auto shader = Resource::LoadShader("source/Shaders/2D_shader.vert", "source/Shaders/2D_shader.frag", NULL, "2D_shader");

	//World::addGameSystem(new TestSystem());

	for (uint32 i = 0; i < 100000; i++)
	{
		float x = RandomNumber::Range(-Window::getWidth() / 180.0f, Window::getWidth() / 180.0f);
		float y = RandomNumber::Range(-Window::getHeight() / 180.0f, Window::getHeight() / 180.0f);

		auto entt = World::CreateEntity();
		entt->add_Component<Transform>(glm::vec2(x, y), 0.0f, glm::vec2(1.0f, 1.0f));
		entt->add_Component<Sprite>(Resource::getShader("2D_shader"), Resource::getTexture("sprite"), 2.0f, 0.0f, 1.0f, 6.0f);
	}
}

void Test_Scene::Update()
{

}

void Test_Scene::Close()
{

}


Test_Scene::~Test_Scene()
{

}
