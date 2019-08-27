#include "GameScene.h"

GameScene::GameScene()
{

}



void GameScene::Init()
{
	//auto Sprites = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");
	//auto Sprite_test = Resource::LoadTexture("Resources/Sprites/Sprites.png", true, "sprite");
	//auto Sprite_test2 = Resource::LoadTexture("Resources/Sprites/Front.png", true, "sop");

	World::addGameSystem(new FPSCamera());


	auto camera = World::CreateEntity();
	camera->add_Component<Camera3D>(60.0f);
	camera->add_Component<Transform>(glm::vec3(0,0,0), glm::vec3(0,0,0), glm::vec3(0,0,0));

}



void GameScene::Update()
{

}


void GameScene::Debug()
{

}

void GameScene::Close()
{

}


GameScene::~GameScene()
{

}