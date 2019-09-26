#pragma once

#include <FireLight.h>

class Grid: public Component {
public:
	Grid() = default;
	Grid(Scene* scene);


	void Init();
	void Update();

private:
	Scene* m_scene;
	glm::vec2 GetType(int index);


	const glm::vec2 dirt     = glm::vec2(11, 01);
	const glm::vec2 dirt_dry = glm::vec2(02, 00);
	const glm::vec2 dirt_wet = glm::vec2(14, 05);
	const glm::vec2 seedling = glm::vec2(13, 06);
	const glm::vec2 tree     = glm::vec2(04, 02);
	const glm::vec2 skull    = glm::vec2(00, 15);
};