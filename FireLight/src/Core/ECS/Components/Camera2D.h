#pragma once

#include "../Component.h"
#include <glm/glm.hpp>

struct Camera2D : public Component<Camera2D>
{
	Camera2D(glm::mat4 proj) : projection(proj)
	{

	}

	Camera2D()
	{

	}


	glm::mat4 projection;
};