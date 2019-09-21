#include "Test_Scene.h"
#include <math.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "..\Log.h"
void Test_Scene::Init()
{
	auto player = CreateGameOject();
	player.lock()->AddComponent(std::make_shared<Sprite>());
	FL::LOG_ERROR_ENGINE("This shouldn't work!");
	FL::LOG_DOUBT_ENGINE("Should this work?");
	FL::LOG_INFO("Working...");
	FL::LOG_SUCC_ENGINE("This is working!");

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
	FL::Log::Draw();
}
