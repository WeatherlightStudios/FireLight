#include "Test_Scene.h"
#include <math.h>
#include <iostream>

void Test_Scene::Init()
{
	Resource::LoadShader("Resources/Shaders/Terrain_shader.vert", "Resources/Shaders/Terrain_shader.frag", NULL, "terrain_shader");
	Resource::LoadTexture("Resources/Texture/Boxes.png", true, "TestBox");
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
