#include "MainGameScene.h"

MainGameScene::MainGameScene() {

}

void MainGameScene::Init() {
	auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png",    true, "sheet_black");
	auto shader = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "2D_shader");

	const int TILE_WIDTH = 16;
	int space = TILE_WIDTH * 5;

	//World::addGameSystem(new WeaponSystem(camera, entt));
	auto dirt = World::CreateEntity();
	dirt->add_Component<Transform>(glm::vec2(0, 0), 0.0f, glm::vec2(4.0f, 4.0f));
	dirt->add_Component<Sprite>(11.0f, 1.0f, 32.0f, 32.0f);
	dirt->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));
	
	auto dirt_dry = World::CreateEntity();
	dirt_dry->add_Component<Transform>(glm::vec2(space, 0), 0.0f, glm::vec2(4.0f, 4.0f));
	dirt_dry->add_Component<Sprite>(2.0f, 0.0f, 32.0f, 32.0f);
	dirt_dry->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));

	auto dirt_wet = World::CreateEntity();
	dirt_wet->add_Component<Transform>(glm::vec2(0, space), 0.0f, glm::vec2(4.0f, 4.0f));
	dirt_wet->add_Component<Sprite>(14.0f, 5.0f, 32.0f, 32.0f);
	dirt_wet->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));

	auto seedling = World::CreateEntity();
	seedling->add_Component<Transform>(glm::vec2(space, space), 0.0f, glm::vec2(4.0f, 4.0f));
	seedling->add_Component<Sprite>(13.0f, 6.0f, 32.0f, 32.0f);
	seedling->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));

	auto tree = World::CreateEntity();
	tree->add_Component<Transform>(glm::vec2(space*2, 0), 0.0f, glm::vec2(4.0f, 4.0f));
	tree->add_Component<Sprite>(4.0f, 2.0f, 32.0f, 32.0f);
	tree->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));

	auto skull = World::CreateEntity();
	skull->add_Component<Transform>(glm::vec2(space*2, space), 0.0f, glm::vec2(4.0f, 4.0f));
	skull->add_Component<Sprite>(0.0f, 15.0f, 32.0f, 32.0f);
	skull->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));



	auto sun = World::CreateEntity();
	sun->add_Component<Transform>(glm::vec2(space*2, space*2), 0.0f, glm::vec2(4.0f, 4.0f));
	sun->add_Component<Sprite>(16.0f, 22.0f, 32.0f, 32.0f);
	sun->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));

	auto water = World::CreateEntity();
	water->add_Component<Transform>(glm::vec2(0, space*2), 0.0f, glm::vec2(4.0f, 4.0f));
	water->add_Component<Sprite>(14.0f, 18.0f, 32.0f, 32.0f);
	water->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_transp"));

	auto seed = World::CreateEntity();
	seed->add_Component<Transform>(glm::vec2(space, space*2), 0.0f, glm::vec2(4.0f, 4.0f));
	seed->add_Component<Sprite>(20.0f, 5.0f, 32.0f, 32.0f);
	seed->add_Component<MeshRender>(Resource::getShader("2D_shader"), Resource::getTexture("sheet_black"));
	

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