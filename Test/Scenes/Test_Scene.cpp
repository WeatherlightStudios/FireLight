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
	auto texture02 = Resource::LoadTexture("source/Texture/tilea2.png", true, "tile");
	auto texture03 = Resource::LoadTexture("source/Texture/WormChar.png", true, "tile2");
	auto shader = Resource::LoadShader("source/Shaders/2D_shader.vert", "source/Shaders/2D_shader.frag", NULL, "2D_shader");

	//World::addGameSystem(new TestSystem());
	auto entt = World::CreateEntity();
	entt->add_Component<Transform>(glm::vec2(0, 0), 0.0f, glm::vec2(1.0f, 1.0f));
	entt->add_Component<Sprite>(2.0f, 0.0f, 1.0f, 6.0f);
	entt->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sprite"));


	for (int y = 0; y < 1000; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			auto tile  = World::CreateEntity();
			tile->add_Component<Transform>(glm::vec2(x * 32, y * 32), 0.0f, glm::vec2(1.0f, 1.0f));
			tile->add_Component<Sprite>(0.0f, 0.0f, 12.0f, 16.0f);
			tile->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("tile"));
		}
	}

	
	//auto tile02 = World::CreateEntity();
	//tile02->add_Component<Transform>(glm::vec2(0, 1), 0.0f, glm::vec2(1.0f, 1.0f));
	//tile02->add_Component<Sprite>(2.0f, 0.0f, 1.0f, 6.0f);
	//tile02->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("tile2"));
	//
	/*for (uint32 i = 0; i < 1000; i++)
	{
		float x = RandomNumber::Range(-Window::getWidth() / 180.0f, Window::getWidth() / 180.0f);
		float y = RandomNumber::Range(-Window::getHeight() / 180.0f, Window::getHeight() / 180.0f);

		auto entt = World::CreateEntity();
		entt->add_Component<Transform>(glm::vec2(x, y), 0.0f, glm::vec2(1.0f, 1.0f));
		entt->add_Component<Sprite>(2.0f, 0.0f, 1.0f, 6.0f);
		entt->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sprite"));
	}*/
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
