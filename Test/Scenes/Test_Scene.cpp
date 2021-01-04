#include "Test_Scene.h"
#include <math.h>
#include <iostream>

void Test_Scene::Init()
{
	ResourceManager::LoadShader("Resources/test.glsl", "voxel");
	ResourceManager::LoadShader("Resources/defaultTest.glsl", "shader");

	auto box = CreateGameOject();
	box->AddComponent(std::make_shared<Transform>(glm::vec3(0,1,0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	box->AddComponent(std::make_shared<Box>());
	box->AddComponent(std::make_shared<Moviment>());

	auto box2 = CreateGameOject();
	box2->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(5, 1, 5)));
	box2->AddComponent(std::make_shared<Box>());

	auto camera = CreateGameOject();
	camera->AddComponent(std::make_shared<Transform>(glm::vec3(0, 0, -10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)));
	camera->AddComponent(std::make_shared<Camera>(Camera_Type::PERSPECTIVE, 60.0f, 0.01f, 10000.0f));
	camera->AddComponent(std::make_shared <TestComponent>());

	glEnable(GL_MULTISAMPLE);
}


void Test_Scene::Update()
{	

	if (FL::Input::IsKeyDown(FL::KEYCODE::KEY_V))
	{
		glfwWindowHint(GLFW_SAMPLES, 16);
	}
}

void Test_Scene::Close()
{

}

void Test_Scene::Debug()
{
}
