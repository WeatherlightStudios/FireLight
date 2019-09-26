#include "Test_Scene.h"
#include <math.h>
#include <iostream>

void Test_Scene::Init()
{
	Resource::LoadTexture("Resources/Texture/Sprite-Test.png", true, "sprite");
	Resource::LoadTexture("Resources/Texture/Front.png", true, "spr");


	auto player = CreateGameOject();
	player->AddComponent(std::make_shared<Transform>(glm::vec2(0,0), 0.0f, glm::vec2(1, 1)));
	player->AddComponent(std::make_shared<Sprite>());
	player->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	player->GetComponent<Sprite>()->m_row = glm::vec2(18, 13);
	player->GetComponent<Sprite>()->m_offset = glm::vec2(0,0);

	auto player2 = CreateGameOject();
	player2->AddComponent(std::make_shared<Transform>(glm::vec2(0, 0), 0.0f, glm::vec2(1, 1)));
	player2->AddComponent(std::make_shared<Sprite>());
	player2->GetComponent<Sprite>()->m_texture = Resource::getTexture("spr");
	player2->GetComponent<Sprite>()->m_row = glm::vec2(6, 1);
	player2->GetComponent<Sprite>()->m_offset = glm::vec2(0, 0);


}

void Test_Scene::Update()
{	

}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{
}
