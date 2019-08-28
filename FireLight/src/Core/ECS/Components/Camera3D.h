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

	float velocity = 5.0f;
	float rotVelocity = 1.0f;
	float speedMultiplier = 3.0f;

	float planeDist[2] = { 0.1f, 100.0f };
	//float nearDistance = 0.1f;
	//float farDistance = 100.0f;
};