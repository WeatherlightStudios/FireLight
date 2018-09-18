#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Component.h"
#include <glm/glm.hpp>

struct Transform : Component<Transform>
{
	Transform(glm::vec3 pos, float rot, glm::vec2 scal) : position(pos) , rotation (rot), scale(scal)
	{

	}

	Transform()
	{

	}

	glm::vec3 position;
	float rotation;
	glm::vec2 scale;
};

#endif TRANSFORM_H