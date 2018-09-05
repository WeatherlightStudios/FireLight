#ifndef SPRITE_H
#define SPRITE_H

#include "../Component.h"
#include "../../../Utility/Resources/Shader.h"
#include "../../../Utility/Resources/Texture.h"


struct Sprite : Component<Sprite>
{
	int m_widht;
	int m_height;

	Texture m_texture;
	Shader m_shader;

	float m_offsetX, m_offsetY;
	float m_row, m_collum;


	float vertices[]
	{
		//Position			//UV
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f,
		-0.5f, 0.5f, 0.0f,  0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,  1.0f, 0.0f,

		0.5f, 0.5f, 0.0f,  1.0f, 0.0f,
		0.5f, -0.5f, 0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f
	};

};

#endif