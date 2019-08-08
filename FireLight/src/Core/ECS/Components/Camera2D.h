#pragma once

#include "../Component.h"
#include <glm/glm.hpp>
#include "../../../Render/RenderSystem.h"

struct Camera2D : public Component<Camera2D>
{
	Camera2D(glm::mat4 proj) : projection(proj)
	{

	}

	Camera2D()
	{
	}

	glm::mat4 projection = glm::mat4(1.0f);
};