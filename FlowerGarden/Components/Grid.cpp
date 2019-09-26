#include "Grid.h"

Grid::Grid(Scene* scene){
	//FL::LOG_SUCC("Constructed Grid Object");
	//FL::LOG_INFO("Scene is ", scene);
	m_scene = scene;
}

void Grid::Init() {
	//FL::LOG_SUCC("Started Grid");
	/*
	auto dirt = m_scene->CreateGameOject();
	dirt->AddComponent(std::make_shared<Transform>(glm::vec2(0, 0), glm::vec2(2, 2)));
	dirt->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(11, 1)));

	auto dirt_dry = m_scene->CreateGameOject();
	dirt_dry->AddComponent(std::make_shared<Transform>(glm::vec2(100, 0), glm::vec2(2, 2)));
	dirt_dry->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(2, 0)));

	auto dirt_wet = m_scene->CreateGameOject();
	dirt_wet->AddComponent(std::make_shared<Transform>(glm::vec2(-100, 0), glm::vec2(2, 2)));
	dirt_wet->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(14, 5)));

	auto seedling = m_scene->CreateGameOject();
	seedling->AddComponent(std::make_shared<Transform>(glm::vec2(0, 100), glm::vec2(2, 2)));
	seedling->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(13, 6)));

	auto tree = m_scene->CreateGameOject();
	tree->AddComponent(std::make_shared<Transform>(glm::vec2(0, -100), glm::vec2(2, 2)));
	tree->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(4, 2)));

	auto skull = m_scene->CreateGameOject();
	skull->AddComponent(std::make_shared<Transform>(glm::vec2(100, 100), glm::vec2(2, 2)));
	skull->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(0, 15)));
	*/

	float GRID_SIZE = 4.0f;
	float TILE_SIZE = 32.0f;
	float TILE_SCALE = 4.0f;
	RandomNumber::SetSeed(666);
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			auto pos = glm::vec2(x * TILE_SIZE * TILE_SCALE, y * TILE_SIZE * TILE_SCALE);
			pos -= glm::vec2((GRID_SIZE * TILE_SIZE * TILE_SCALE / 2.0f), (GRID_SIZE * TILE_SIZE * TILE_SCALE / 2.0f));
			auto tile = m_scene->CreateGameOject();
			tile->AddComponent(std::make_shared<Transform>(pos, glm::vec2(TILE_SCALE, TILE_SCALE)));
			tile->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32.0f, 32.0f), GetType(RandomNumber::Range(1.0f,6.0f))));
		}
	}
}

glm::vec2 Grid::GetType(int index) {
	switch (index)
	{
	case 0: return dirt;
	case 1: return dirt_dry;
	case 2: return dirt_wet;
	case 3: return seedling;
	case 4: return tree;
	case 5: return skull;
	default:
		throw "invalid index";
		break;
	}
}
void Grid::Update() {
	

}