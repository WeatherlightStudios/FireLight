#ifndef MESH_H
#define MESH_H

#include "../../../Render/OpenGL/IndexBuffer.h"
#include "../../../Render/OpenGL/VertexBuffer.h"
#include "../../../Render/OpenGL/VertexArrayBuffer.h"

struct MeshRender
{
	VertexBuffer m_vbo;
	GLuint VAO;
	IndexBuffer m_ibo;
};

#endif