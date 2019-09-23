#ifndef SPRITE_H
#define SPRITE_H

#include "../../Core/Component.h"
#include <glm/glm.hpp>

#include "../../../imgui/imgui.h"

#include "../../Utility/Resource.h"


class Sprite : public Component
{
public:
	Sprite();
	Sprite(Texture tex, glm::vec2 rows, glm::vec2 offset);
	~Sprite();

	void Debug();

public:

	glm::vec2 m_row;
	glm::vec2 m_offset;

	Texture m_texture;


};

#endif