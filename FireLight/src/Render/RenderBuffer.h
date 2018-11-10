#pragma once

#include<GL/gl3w.h>
#include <glm/glm.hpp>
#include <iostream>


struct GL_Sprite
{
	glm::vec3 vertex;
	glm::vec2 uv;
};


class RenderBuffer
{
public:
	RenderBuffer();

	void Begin();

	void addData();

	void UpdateData(GL_Sprite* data);

	void End();


	void beginDraw();

	void Draw(GLuint begin, GLuint end);

	void endDraw();

	~RenderBuffer();


private:
	GLuint VAO, VBO;

	uint32_t index;

	GL_Sprite* Buffer;

	

};