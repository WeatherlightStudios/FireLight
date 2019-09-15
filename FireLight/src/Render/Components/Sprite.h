#ifndef SPRITE_H
#define SPRITE_H

#include "../../Core/Component.h"
#include <glm/glm.hpp>

#include "../../../imgui/imgui.h"
class Sprite : public Component
{
public:
	Sprite();


	void Init();
	void Update();
	void Debug();

	~Sprite();


public:
	glm::vec2 m_position;
	glm::vec2 m_scale;
	float m_rotation;

	glm::vec2 m_row;
	glm::vec2 m_offset;



};

#endif