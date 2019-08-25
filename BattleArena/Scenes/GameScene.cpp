#include "GameScene.h"

GameScene::GameScene()
{

}



void GameScene::Init()
{
	auto Sprites = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");
	auto Sprite_test = Resource::LoadTexture("Resources/Sprites/Sprites.png", true, "sprite");
	auto Sprite_test2 = Resource::LoadTexture("Resources/Sprites/Front.png", true, "sop");

	//auto shader = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "2D_shader");
	//auto shad = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");

	//World::addGameSystem(new PlayerMovement_S());
	//World::addGameSystem(new Camera2DSystem());

	/*auto entt = World::CreateEntity();
	entt->add_Component<Transform>(glm::vec2(0, 0), 0.0f, glm::vec2(1.0f, 1.0f));
	entt->add_Component<Sprite>(4, 8, 16.0f, 16.0f);
	entt->add_Component<MeshRender>("shader", Resource::getTexture("sprite"));

	auto entt2 = World::CreateEntity();
	entt2->add_Component<Transform>(glm::vec2(64, 0), 0.0f, glm::vec2(1, 1));
	entt2->add_Component<Sprite>(2, 0, 1, 6);
	entt2->add_Component<MeshRender>("shader", Resource::getTexture("sop"));

	auto entt3 = World::CreateEntity();
	entt3->add_Component<Transform>(glm::vec2(5, 0), 0.0f, glm::vec2(1.0f, 1.0f));
	entt3->add_Component<Sprite>(4, 8, 16.0f, 16.0f);
	entt3->add_Component<MeshRender>("shader", Resource::getTexture("sprite"));*/


	for (int i = 0; i < 100000; i++)
	{

		auto weapon = World::CreateEntity();
		weapon->add_Component<Transform>(glm::vec2(RandomNumber::Range(-100,100), RandomNumber::Range(-100, 100)), 0.0f, glm::vec2(1.0f, 1.0f));
		weapon->add_Component<Sprite>(4.0f, 8.0f, 16.0f, 16.0f);
		weapon->add_Component<MeshRender>("shader", Resource::getTexture("sprite"));
	}

	//auto camera = World::CreateEntity();
	//camera->add_Component<Transform>(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(1.0f, 1.0f));
	//camera->add_Component<Camera2D>();

	//World::addGameSystem(new WeaponSystem(camera, entt));

	//RenderSystem::setCamera(camera);
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