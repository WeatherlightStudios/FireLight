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

	void gen_quad();
	void gen_triangle();
	void gen_circle();

	glm::vec3 get_position() { return m_position; }
	glm::vec3 get_scale() { return m_scale; }

	void set_color(glm::vec3 color);

	void set_trasform(glm::vec3 transform);
	void set_scale(glm::vec3 scale);

	void translate(glm::vec3 transform);
	void scale(glm::vec3 scale);

	void Render(Camera cam);

	~Renderable();


private:

	GLuint VBO, VAO;

	glm::vec3 m_position;
	glm::vec3 m_scale;
	glm::quat m_rotation;

	glm::vec3 m_color;
	glm::mat4 model;

};

