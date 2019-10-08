#include "Test_Scene.h"
#include <math.h>
#include <iostream>

void Test_Scene::Init()
{
	Resource::LoadShader("Resources/Shaders/Terrain_shader.vert", "Resources/Shaders/Terrain_shader.frag", NULL, "terrain_shader");
	Resource::LoadTexture("Resources/Texture/Boxes.png", true, "TestBox");


	auto camera = CreateGameOject();
	camera->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	camera->AddComponent(std::make_shared<Camera>(Camera_Type::PERSPECTIVE, 60.0f, 0.01f, 1000.0f));
	camera->AddComponent(std::make_shared <TestComponent>());

	auto Terrain = CreateGameOject();
	Terrain->AddComponent(std::make_shared<Transform>());
	Terrain->AddComponent(std::make_shared<TerrainComponent>());



}

void Test_Scene::Update()
{	
	/*if (FL::Window::isKeyDown(KEYCODE::KEY_A))
	{
		auto obj = CreateGameOject();
		obj->AddComponent(std::make_shared<Transform>(glm::vec2(RandomNumber::Range(-50, 50), RandomNumber::Range(-50, 50)), 0.0f, glm::vec2(1, 1)));
		obj->AddComponent(std::make_shared<Sprite>());
		obj->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
		obj->GetComponent<Sprite>()->m_row = glm::vec2(18, 13);
		obj->GetComponent<Sprite>()->m_offset = glm::vec2(0, 0);
		obj->GetComponent<Sprite>()->ZLayer = 1;
	}*/
}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{
}
