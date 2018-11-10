#pragma once

#include <glm/glm.hpp>
#include "../Component.h"
#include "../../../Utility/Resources/Shader.h"
#include "../../../Utility/Resources/Texture.h"


struct Sprite : public Component<Sprite>
{
	Sprite(float offsetX, float offsetY, float rows, float collums) :
		 OffsetX(offsetX), OffsetY(offsetY), Rows(rows), Collums(collums)
	{

	}

	float OffsetX;
	float OffsetY;

	float Rows;
	float Collums;

};