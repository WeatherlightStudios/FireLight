
#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Renderable.h"
#include "../Core/SceneNode.h"
#include "OpenGL\GLUtility.h"
#include "../Utility/ResourceManager.h"
#include <GL\gl3w.h>
#include <glm\glm.hpp>

class Cube :  public Renderable, public SceneNode
{
public:
	Cube();

	void init();

	void Draw(Camera *camera);
	glm::vec3 lerp(const glm::vec3& A, const glm::vec3& B, float t) {
		return A * t + B * (1.f - t);
		//return (1 - t) * A + t * B;
	}
	
	~Cube();

private:

	VertexBuffer m_vbo;
	IndexBuffer m_ibo;

	glm::mat4 model;

	GLuint VAO;
	GLuint EBO;



};

#endif