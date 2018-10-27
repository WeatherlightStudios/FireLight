#pragma once

#include <glm/glm.hpp>
#include "../Component.h"
#include "../../../Utility/Resources/Shader.h"
#include "../../../Utility/Resources/Texture.h"


struct Sprite : public Component<Sprite>
{
	Sprite(Shader shader, Texture texture, float offsetX, float offsetY, float rows, float collums) :
		Shader(shader), Texture(texture), OffsetX(offsetX), OffsetY(offsetY), Rows(rows), Collums(collums)
	{

	}

	Shader Shader;
	Texture Texture;

	float OffsetX;
	float OffsetY;

	float Rows;
	float Collums;

};