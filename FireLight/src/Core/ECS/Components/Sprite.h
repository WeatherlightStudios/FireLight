#ifndef SPRITE_H
#define SPRITE_H

#include "../Component.h"
#include "../../../Utility/Resources/Shader.h"
#include "../../../Utility/Resources/Texture.h"


struct Sprite : Component<Sprite>
{

	Sprite(Texture texture, Shader shader, float row, float columns, float offsetX, float offsetY,int width, int height) : 
		m_texture(texture), 
		m_shader(shader),
		m_row(row), 
		m_collum(columns), 
		m_offsetX(offsetX),
		m_offsetY(offsetY),
		m_widht(width),
		m_height(height)
	{

	}

	Sprite()
	{

	}

	int m_widht;
	int m_height;

	Texture m_texture;
	Shader m_shader;

	float m_offsetX, m_offsetY;
	float m_row, m_collum;


	float vertices[30]
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