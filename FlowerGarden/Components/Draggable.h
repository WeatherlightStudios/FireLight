#pragma once

#include <FireLight.h>
#include <string>

COMPONENT(Draggable)
{
public:
	enum PickUpType { Water, Sun, Seed};

	Draggable(PickUpType type, glm::vec2 homePos): type(type), homePos(homePos){ }

	bool isPicked = false;
	glm::vec2 homePos;
	float returnSpeed = 6.0f;

	PickUpType type;
};