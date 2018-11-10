#pragma once

#include "../Utility/Resources/Shader.h"
#include "../Utility/Resources/Texture.h"


struct Material
{
	Material(Shader shader, Texture texture) : m_texture(texture), m_shader(shader)
	{

	}

	Texture m_texture;
	Shader m_shader;
};