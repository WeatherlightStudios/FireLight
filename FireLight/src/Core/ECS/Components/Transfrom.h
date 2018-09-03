#ifndef TRANSFORM_H
#define TRANSFROM_H

#include "../Component.h"
#include <glm/glm.hpp>

struct Transform : Component<Transform>
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

#endif