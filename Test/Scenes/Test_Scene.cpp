#include "Test_Scene.h"
#include <math.h>
#include <iostream>

void Test_Scene::Init()
{
	Resource::LoadTexture("Resources/Texture/Sprite-Test.png", true, "sprite");


	auto player = CreateGameOject();
	player->AddComponent(std::make_shared<Transform>(glm::vec2(0,0), glm::vec2(1,1), 0.0f));
	player->AddComponent(std::make_shared<Sprite>());

	FL::LOG_ERROR_ENGINE("This shouldn't work!");
	FL::LOG_DOUBT_ENGINE("Should this work?");
	FL::LOG_INFO("Working...");
	FL::LOG_SUCC_ENGINE("This is working!");

	player->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	player->GetComponent<Sprite>()->m_row = glm::vec2(1, 1);
	player->GetComponent<Sprite>()->m_offset = glm::vec2(0,0);

	FL::LOG_ERROR("frase con numero ", 3.14f);


}

void Test_Scene::Update()
{	
	if (FL::Window::isKeyDown(KEYCODE::KEY_SPACE)) {
		FL::LOG_ERROR("This shouldn't work!");
	}
	if (FL::Window::isKeyDown(KEYCODE::KEY_W)) {
		FL::LOG_INFO_ENGINE("Working at stuff...");
		FL::LOG_SUCC_ENGINE("Succeded at doing stuff!");
	}
	if (FL::Window::isKeyDown(KEYCODE::KEY_S)) {
		FL::LOG_INFO_ENGINE("Working at stuff...");
		FL::LOG_ERROR_ENGINE("Error at doing stuff!");
	}
	if (FL::Window::isKeyDown(KEYCODE::KEY_A)) {
		FL::LOG_INFO("Working at stuff...");
		FL::LOG_SUCC("Succeded at doing stuff!");
	}
	if (FL::Window::isKeyDown(KEYCODE::KEY_D)) {
		FL::LOG_INFO("Working at stuff...");
		FL::LOG_ERROR("Error at doing stuff!");
	}
}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{
}
