#include "GameScene.h"

GameScene::GameScene()
{

}



void GameScene::Init()
{
	//auto Sprites = Resource::LoadTexture("Resources/Sprites/Sprites.png", true, "sprite");
	//auto Sprite_test = Resource::LoadTexture("Resources/Sprites/character.png", true, "op");

	//auto shader = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "2D_shader");
	//auto shad = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");

	//World::addGameSystem(new PlayerMovement_S());
	//World::addGameSystem(new Camera2DSystem());

	/*auto entt = World::CreateEntity();
	entt->add_Component<Transform>(glm::vec2(100.0f, 1), 0.0f, glm::vec2(2.0f, 2.0f));
	entt->add_Component<Sprite>(4.0f, 8.0f, 16.0f, 16.0f);
	entt->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sprite"));*/

	/*for (int i = 0; i < 150000; i++)
	{

		auto weapon = World::CreateEntity();
		weapon->add_Component<Transform>(glm::vec2(RandomNumber::Range(-100,100), RandomNumber::Range(-100, 100)), 0.0f, glm::vec2(1.0f, 1.0f));
		weapon->add_Component<Sprite>(4.0f, 8.0f, 16.0f, 16.0f);
		weapon->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sprite"));
	}*/

	auto camera = World::CreateEntity();
	camera->add_Component<Transform>(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(1.0f, 1.0f));
	camera->add_Component<Camera2D>();

	//World::addGameSystem(new WeaponSystem(camera, entt));

	RenderSystem::setCamera(camera);
}



void GameScene::Update()
{


	/*if (FL::Input::IsKeyUp(KEYCODE::KEY_W))
	{
		std::cout << "K is Up" << std::endl;
	}


	if (FL::Input::IsKeyPressed(KEYCODE::KEY_S))
	{
		std::cout << "K is Pressed" << std::endl;
	}*/
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