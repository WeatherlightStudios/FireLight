#pragma once


#include "../Component.h"
#include <glm/glm.hpp>

COMPONENT(Camera3D)
{

	Camera3D(float fov): m_fov(fov)
	{

	}

	Camera3D()
	{

	}

	float m_fov;

	glm::vec3 forward;
	glm::vec3 upward;
	glm::vec3 left;


};