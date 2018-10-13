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
	



	World::addGameSystem(new TestSystem());

	for (uint32 i = 0; i < 1000000; i++)
	{
		auto entity = World::CreateEntity();
		entity->add_Component<Transform>();
	}

	i = 0;
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
