#ifndef SPRITE_HEADER
#define SPRITE_HEADER

#include "Renderable.h"
#include "../Core/SceneNode.h"
#include "OpenGL\GLUtility.h"
#include "../Utility/ResourceManager.h"
#include <GL\gl3w.h>
#include <glm\glm.hpp>

class Sprite : public Renderable, public SceneNode
{

public:
	Sprite(Texture texture, Shader shader);
	~Sprite();

	void init();

	void Draw(Camera2D *camera);

	void setOffset(float x, float y);
	void setRows(float row, float collum);



private:

	VertexBuffer m_vbo;
	IndexBuffer m_ibo;

	glm::mat4 model;

	GLuint VAO;
	GLuint EBO;

	Texture m_texutre;
	Shader m_shader;

	float m_offsetX, m_offsetY;
	float m_row, m_collum;

};

#endif
