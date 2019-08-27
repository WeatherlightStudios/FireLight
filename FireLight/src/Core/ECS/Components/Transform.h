#pragma once

#include <glm/glm.hpp>
#include "../Component.h" 

struct Transform : public Component<Transform>
{
	Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 size) : Position(pos), Rotation(rot), Scale(size)
	{

	}

	Transform() : Position(glm::vec3(0.0f,0.0f,0.0f)), Rotation(glm::vec3(0.0f, 0.0f, 0.0f)), Scale(glm::vec3(1.0f,1.0f,1.0f))
	{

	}

	glm::vec3 Rotation;
	glm::vec3 Position;
	glm::vec3 Scale;

};