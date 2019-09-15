#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H

#include <GL/gl3w.h>
#include "../Utility/Resource.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Components/Sprite.h"


class Simple2DRenderSystem
{
public:
	Simple2DRenderSystem();


	void Init();

	void Draw(Sprite* sp);

	void DrawLine();
	void DrawCircle();
	void DrawQuad();
	
	void DrawFilledQuad();


	~Simple2DRenderSystem();

private:

	GLuint VAO, VBO, IBO;

	glm::mat4 projection;
	glm::mat4 model;




};

#endif