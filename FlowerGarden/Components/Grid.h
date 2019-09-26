#pragma once

#include <FireLight.h>

class Grid: public Component {
public:
	Grid() = default;
	Grid(Scene* scene);

	void Init();
	void Update();

	void CheckTile(std::shared_ptr<GameObject> drag);

private:
	Scene* m_scene;
	//glm::vec2 GetType(int index);
	glm::vec2 CheckMatrix(glm::vec2 tile_offset, glm::vec2 drag_offset);

	std::vector<std::shared_ptr<GameObject>> tiles;
	bool AABBCheck(glm::vec2 pointPos, glm::vec2 squarePos, glm::vec2 squareSize);

	glm::vec2 tileType;
	
	const glm::vec2 dirt_dry = glm::vec2( 0,  0);
	const glm::vec2 dirt     = glm::vec2( 1,  0);
	const glm::vec2 dirt_wet = glm::vec2( 2,  0);
	const glm::vec2 seedling = glm::vec2( 0,  1);
	const glm::vec2 tree     = glm::vec2( 1,  1);
	const glm::vec2 skull    = glm::vec2( 2,  1);
	const glm::vec2 plus1    = glm::vec2(-1, -1);

	glm::vec2 matrix[6][3] = {
		dirt,     skull,    skull,
		dirt_wet, dirt_dry, seedling,
		skull,    dirt,     skull,
		tree,     skull,    dirt,
		skull,    dirt,    dirt,
		skull,    skull,    skull
	};

};