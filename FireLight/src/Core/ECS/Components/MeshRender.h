#pragma once


#include <glm/glm.hpp>
#include "../Component.h"
#include "../../../Utility/Resources/Shader.h"
#include "../../../Utility/Resources/Texture.h"



struct MeshRender : public Component<MeshRender>
{
	MeshRender(Shader shader, Texture texture) : m_shader(shader), m_texture(texture)
	{

	}
	
	Texture m_texture;
	Shader m_shader;

};