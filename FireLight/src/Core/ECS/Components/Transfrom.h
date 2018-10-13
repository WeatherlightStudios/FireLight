#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Component.h"
#include <glm/glm.hpp>

struct Transform : Component<Transform>
{
	Transform(glm::vec3 pos, float rot, glm::vec2 scal) : position(pos) , rotation (rot), scale(scal)
	{

	}

	Transform() : position(glm::vec3(0,0,0)), rotation(0.0f), scale(glm::vec2(1,1))
	{

	}

	glm::vec3 position;
	float rotation;
	glm::vec2 scale;
};

#endif TRANSFORM_H