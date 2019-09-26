#include "Grid.h"

Grid::Grid(Scene* scene){
	//FL::LOG_SUCC("Constructed Grid Object");
	//FL::LOG_INFO("Scene is ", scene);
	m_scene = scene;
}

void Grid::Init() {
	const unsigned int GRID_SIZE = 4;
	const unsigned int TILE_SIZE = 32;
	const unsigned int TILE_SCALE = 4;
	auto offset = glm::vec2(80, 200);
	RandomNumber::SetSeed(666);
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			auto pos = glm::vec2(x * TILE_SIZE * TILE_SCALE, y * TILE_SIZE * TILE_SCALE) + offset;
			pos -= glm::vec2((int)(GRID_SIZE * TILE_SIZE * TILE_SCALE / 2), (int)(GRID_SIZE * TILE_SIZE * TILE_SCALE / 2));
			auto tile = m_scene->CreateGameOject();
			tile->AddComponent(std::make_shared<Transform>(pos, glm::vec2(TILE_SCALE, TILE_SCALE)));
			tile->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(3, 3), GetType(RandomNumber::Range(1,6))));
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