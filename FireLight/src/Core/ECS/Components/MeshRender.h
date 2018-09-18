#ifndef MESH_H
#define MESH_H

#include "../../../Render/OpenGL/IndexBuffer.h"
#include "../../../Render/OpenGL/VertexBuffer.h"
#include "../../../Render/OpenGL/VertexArrayBuffer.h"

#include "../Component.h"

struct MeshRender : Component<MeshRender>
{
	MeshRender(VertexBuffer vbo, GLuint vao, IndexBuffer ibo, glm::mat4 model) : 
		m_vbo(vbo), VAO(vao), m_ibo(ibo), model(model)
	{

	}

	MeshRender()
	{

	}

	VertexBuffer m_vbo;
	GLuint VAO;
	IndexBuffer m_ibo;
	glm::mat4 model;
};

#endif