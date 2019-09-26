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


	const glm::vec2 dirt_dry = glm::vec2(0, 0);
	const glm::vec2 dirt     = glm::vec2(1, 0);
	const glm::vec2 dirt_wet = glm::vec2(2, 0);
	const glm::vec2 seedling = glm::vec2(0, 1);
	const glm::vec2 tree     = glm::vec2(1, 1);
	const glm::vec2 skull    = glm::vec2(2, 1);
};