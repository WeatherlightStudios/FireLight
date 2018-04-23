
#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Renderable.h"
#include "../Core/SceneNode.h"
#include "OpenGL\GLUtility.h"
#include "../Utility/ResourceManager.h"
#include <GL\gl3w.h>

class Cube :  public Renderable, public SceneNode
{
public:
	Cube();

	void init();

	void Draw(Camera *camera);
	
	~Cube();

private:

	VertexBuffer m_vbo;
	IndexBuffer m_ibo;

	glm::mat4 model;

	GLuint VAO;
	GLuint EBO;



};

#endif