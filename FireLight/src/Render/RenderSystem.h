#pragma once

#include <glm/glm.hpp>
#include <GL/gl3w.h>

#include "../Core/ECS/Components/Transform.h"
#include "../Core/ECS/Components/Test.h"
#include "../Core/ECS/Components/Sprite.h"

#include "../Utility/Resource.h"

#include "../Core/ECS/Systems/Camera2DSystem.h";
#include "../Core/ECS/Systems/TestSystem.h";
#include "../Core/ECS/Systems/SpriteRenderSystem.h";
#include "../Core/ECS/World.h";
#include "../Utility/RandomNumber.h"


#include "../Utility/Resource.h"

#include <vector>
#include <cstdlib>
#include <algorithm>

#define VERTEX_PER_QUAD 6
#define MAX_SPRITES 500000
#define VERTEX_BUFFER_SIZE (sizeof(float) * 6 * 6) * MAX_SPRITES
#define UV_BUFFER_SIZE (sizeof(float) * 3 * 6) * MAX_SPRITES
#define MAX_VERTICES MAX_SPRITES * VERTEX_PER_QUAD



class RenderSystem
{
public:
	RenderSystem();

	void Init();

	void addSprite(float x, float y, int r, int g, int b);

	void UpdateBuffer();

	void Debug();

 	void Draw();

	void Close();

	~RenderSystem();

private:

	GLuint VAO;
	GLuint VBO;

	glm::mat4 m_projection;

	float* buffer;
	float* current_buffer;

	int m_num_of_sprites;
	int sprite_index;

};
