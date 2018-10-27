#pragma once

#include <glm/glm.hpp>
#include "../Component.h" 

struct Transform : public Component<Transform>
{
	Transform(glm::vec2 pos, float rot, glm::vec2 size) : Position(pos), Rotation(rot), Scale(size)
	{

	}

	Transform() : Position(glm::vec2(0.0f,0.0f)), Rotation(0.0f), Scale(glm::vec2(1.0f,1.0f))
	{

	}

	glm::vec2 Position;
	glm::vec2 Scale;
	float Rotation;

};