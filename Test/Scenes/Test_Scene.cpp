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
	Resource::LoadTexture("source/Texture/Sprite-Test.png", true, "sprite");


	auto player = CreateGameOject();
	player.lock()->AddComponent(std::make_shared<Transform>(glm::vec2(0,0), glm::vec2(1,1), 0.0f));

	player.lock()->AddComponent(std::make_shared<Sprite>());

	player.lock()->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	player.lock()->GetComponent<Sprite>()->m_row = glm::vec2(1, 1);
	player.lock()->GetComponent<Sprite>()->m_offset = glm::vec2(0,0);



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


Test_Scene::~Test_Scene()
{

}
