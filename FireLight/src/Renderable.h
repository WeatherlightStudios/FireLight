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

	void Render(Camera cam);

	~Renderable();


private:

	GLuint VBO, VAO, IBO;

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	vertex_buffer m_buffer[6000 * 6000];

};

