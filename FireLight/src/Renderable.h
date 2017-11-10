#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "GL\gl3w.h"
#include "Camera.h"
#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <string>
#include "SceneNode.h"
#include "Utility\Resources\Texture.h"

struct vertex_buffer
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 uv;
};


class Renderable : public SceneNode
{
public:
	Renderable();

	void init();

	//void set_color(glm::vec3 color);
	void set_texture(std::string texture);
	void set_texture_offset(glm::vec2 offset);
	void set_texture_row(glm::vec2 rows);
	void Render(Camera cam);

	~Renderable();


private:

	GLuint VBO, VAO;

	glm::vec3 m_color;
	glm::mat4 model;

	std::string m_texture;

	glm::vec2 m_offset;
	glm::vec2 m_rows;



};

#endif

