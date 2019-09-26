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
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			auto pos = glm::vec2(x * TILE_SIZE * TILE_SCALE, y * TILE_SIZE * TILE_SCALE) + offset;
			pos -= glm::vec2((int)(GRID_SIZE * TILE_SIZE * TILE_SCALE / 2), (int)(GRID_SIZE * TILE_SIZE * TILE_SCALE / 2));
			auto tile = m_scene->CreateGameOject();
			tile->AddComponent(std::make_shared<Transform>(pos, glm::vec2(TILE_SCALE, TILE_SCALE)));
			tile->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(3, 3), dirt, 0));
			tiles.push_back(tile);
		}
	}
}

void Grid::CheckTile(std::shared_ptr<GameObject> drag) {
	FL::LOG_INFO("Starting Tile Check");
	auto transform = drag->GetComponent<Transform>();
	for (auto& groundTile : tiles) {
		auto tileTrans = groundTile->GetComponent<Transform>();
		auto scale = glm::vec2(tileTrans->GetScale().y * 16, tileTrans->GetScale().y * 16);
		if (AABBCheck(transform->GetPosition(), tileTrans->GetPosition(), scale)) {
			FL::LOG_SUCC("Tile Found! Position ", tileTrans->GetPosition());
			auto tile_offset = groundTile->GetComponent<Sprite>()->m_offset;
			auto drag_offset = drag->GetComponent<Sprite>()->m_offset;
			auto result = CheckMatrix(tile_offset, drag_offset);
			groundTile->GetComponent<Sprite>()->m_offset = result;
			FL::LOG_INFO("Now this should switch to ", result);
			//break;
		}
	}
	m_scene->RemoveGameObject(drag);
}

bool Grid::AABBCheck(glm::vec2 pointPos, glm::vec2 squarePos, glm::vec2 squareSize) {
	if (pointPos.x > squarePos.x + squareSize.x || pointPos.x < squarePos.x - squareSize.x) {
		return false;
	}
	
	if (pointPos.y > squarePos.y + squareSize.y || pointPos.y < squarePos.y - squareSize.y) {
		return false;
	}

	return true;
}

glm::vec2 Grid::CheckMatrix(glm::vec2 tile_offset, glm::vec2 drag_offset) {
	int tile_ind = tile_offset.y * 3 + tile_offset.x;
	int drag_ind = drag_offset.y * 3 + drag_offset.x - 6;

	return matrix[tile_ind][drag_ind];
}

void Grid::Update() {

}
