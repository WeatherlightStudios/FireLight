#ifndef CAMERA2D_H
#define CAMERA2D_H

#include "../Component.h"
#include <glm/glm.hpp>

struct Camera2D : Component<Camera2D>
{
	Camera2D(glm::mat4 projection) : m_projection(projection)
	{

	}

	Camera2D()
	{

	}

	glm::mat4 m_projection;
};



#endif