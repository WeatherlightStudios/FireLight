#pragma once

#include <FireLight.h>
#include <string>

class Draggable : public Component
{
public:
	void Init();
	void Update();
	enum PickUpType { Water, Sun, Seed};

	Draggable(PickUpType type, std::shared_ptr<GameObject> tileManager, std::shared_ptr<GameObject> self);

	bool isPicked = false;
	glm::vec2 homePos;
	float returnSpeed = 6.0f;

	PickUpType type;

private:
	bool IsInside(glm::vec2 inputPos, glm::vec2 areaPos, glm::vec2 areaSize);
	std::shared_ptr<GameObject> tileManager;
	std::shared_ptr<GameObject> self;
};