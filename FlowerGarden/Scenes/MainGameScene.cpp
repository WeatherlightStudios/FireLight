#include "MainGameScene.h"

MainGameScene::MainGameScene() {

}

void MainGameScene::Init() {
	auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png",    false, "sheet_black");
	auto shader = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "2D_shader");

	//World::addGameSystem(new WeaponSystem(camera, entt));
	auto entt = World::CreateEntity();
	entt->add_Component<Transform>(glm::vec2(0, 0), 0.0f, glm::vec2(1.0f, 1.0f));
	entt->add_Component<Sprite>(4.0f, 8.0f, 32.0f, 32.0f);
	entt->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));
	/*
	*/
	auto camera = World::CreateEntity();
	camera->add_Component<Transform>(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(1.0f, 1.0f));
	camera->add_Component<Camera2D>();
	RenderSystem::setCamera(camera);

}

void MainGameScene::Update() {

}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

MainGameScene::~MainGameScene(){

}