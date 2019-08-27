#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
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
#define VERTEX_BUFFER_SIZE (sizeof(float) * 5 * 6) * MAX_SPRITES
#define MAX_VERTICES MAX_SPRITES * VERTEX_PER_QUAD

struct GLSprite
{
	float posX, posY;
	float rotatin;
	float zLayer;
	float scaleX, scaleY;
	float offsetX, offsetY;
	int row, collum;
	Texture texture;
	std::string shader;
};

struct Batch
{
	Batch(uint32_t begin, uint32_t count, Texture texture,std::string shader)
	{
		m_begin = begin;
		m_count = count;
		m_texture = texture;
		m_shader = shader;
	}
	uint32_t m_begin;
	uint32_t m_count;
	Texture m_texture;
	std::string m_shader;
};


class RenderSystem
{
public:
	RenderSystem();

	void Init();

	static void addSprite(GLSprite sprite)
	{
		m_sprite.push_back(sprite);
	}

	inline const void vectorRotation(float x, float y, float rot);

	void updateBufferSprite(float x, float y, float rotation,int zLayer, int width, int height, float scaleX, float scaleY,float offsetX, float offsetY, int row, int collums);

	void SrotSprites();

	static bool sortByTexture(GLSprite &textureID, GLSprite &textureID2) { return textureID.texture.ID > textureID2.texture.ID; }

	void CreateBatches();

	//void UpdateBuffer();

	void Debug();

 	void Draw();

	void clearBatch() { m_batches.clear(); }

	void clearSprites() { m_sprite.clear(); }

	void Close();

	~RenderSystem();

private:

	GLuint VAO;
	GLuint VBO;
	GLuint VBOtest;


	glm::mat4 m_projection;

	float* buffer;
	float* current_buffer;

	std::vector<Batch> m_batches;

	static std::vector<GLSprite> m_sprite;

	int m_num_of_sprites;
	int sprite_index;
};
