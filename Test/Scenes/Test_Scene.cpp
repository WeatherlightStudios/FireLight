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

	auto texture = Resource::LoadTexture("source/Texture/Front.png", true, "sprite");
	auto shader = Resource::LoadShader("source/Shaders/2D_shader.vert", "source/Shaders/2D_shader.frag", NULL, "2D_shader");

	auto player = World::CreateEntity();
	player->add_Component<Transform>(glm::vec3(0, 0, 0), 0.0f, glm::vec2(1, 1));
	player->add_Component<Sprite>(texture, shader, 6, 1, 0, 0, 64, 64);
	player->add_Component<MeshRender>();


	auto player02 = World::CreateEntity();
	player02->add_Component<Transform>(glm::vec3(0, 100, 0), 0.0f, glm::vec2(1, 1));
	player02->add_Component<Sprite>(texture, shader, 6, 1, 0, 0, 64, 64);
	player02->add_Component<MeshRender>();


	auto player03 = World::CreateEntity();
	player03->add_Component<Transform>(glm::vec3(100, 100, 0), 0.0f, glm::vec2(1, 1));
	player03->add_Component<Sprite>(texture, shader, 6, 1, 0, 0, 64, 64);
	player03->add_Component<MeshRender>();
	
	i = 0;
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

void Test_Scene::Close()
{

}


Test_Scene::~Test_Scene()
{

}
