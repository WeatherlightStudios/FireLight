#pragma once

#include "GL\gl3w.h"
#include "Camera.h"

struct vertex_buffer
{
	glm::vec3 position;
	glm::vec3 color;
};


class Renderable
{
public:
	Renderable();

	void Init();

	void generateQuad();
	void generateTriangle();
	void generateCircle();

	void Translate(glm::vec3 transform);
	void setColor(glm::vec3 color);
	void Scale(glm::vec3 scale);

	void Render(Camera cam);

	~Renderable();


private:

	GLuint VBO, VAO;
	glm::vec3 m_color;
	glm::mat4 model;

};

