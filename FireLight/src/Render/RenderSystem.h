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


struct GL_Sprite
{
	glm::vec3 vertex;
	glm::vec2 uv;
};

struct SpriteObj
{
	SpriteObj(glm::vec2 Pos,
		glm::vec2 Scale,
		float Rotation,
		float offsetX,
		float offsetY, 
		float row, 
		float collums,
		Shader shader, 
		Texture texture) : m_position(Pos),
		m_scale(Scale),
		m_rot(Rotation), 
		m_OffsetX(offsetX), 
		m_OffsetY(offsetY),
		m_Rows(row),
		m_Collums(collums),
		m_shader(shader),
		m_texture(texture)
	{

	}


	float m_rot;

	float m_OffsetX;
	float m_OffsetY;

	float m_Rows;
	float m_Collums;

	glm::vec2 m_scale;
	glm::vec2 m_position;
	Shader m_shader;
	Texture m_texture;
};


struct Batch
{
	Shader m_shader;
	Texture m_texture;

	int m_begin;
	int m_end;
};

#define VERTEX_PER_QUAD 6
#define MAX_SPRITES 500000
#define BUFFER_SIZE (sizeof(GL_Sprite) * 6) * MAX_SPRITES
#define MAX_VERTICES MAX_SPRITES * VERTEX_PER_QUAD



class RenderSystem
{
public:
	RenderSystem();

	void Init();


	//Need ReWork
	static void addSprite(glm::vec2 pos, glm::vec2 size, float rot, float offX, float offY, float collum, float row, Texture texture);


	void sortSprites()
	{
		std::sort(spriteList.begin(), spriteList.end(), compareTexture);
	};

	void LockBuffer()
	{
		if (gSync)
		{
			glDeleteSync(gSync);
		}
		gSync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
	}

	void Sync()
	{
		if (gSync)
		{
			while (1)
			{
				GLenum waitReturn = glClientWaitSync(gSync, GL_SYNC_FLUSH_COMMANDS_BIT, 1);
				if (waitReturn == GL_ALREADY_SIGNALED || waitReturn == GL_CONDITION_SATISFIED)
					return;
			}
		}
	}

	//TODO:: ReWork in AZDO
	void GenerateBatch();
	void GenerateBuffer();

	//mhe?
	static bool compareTexture(const SpriteObj &a,const  SpriteObj &b);


	//Need new CameraManager
	static void setCamera(EntityHandler* camera);

	
 	void Draw();

	~RenderSystem();

private:
	

	static EntityHandler* m_camera;


	GL_Sprite* renderBuffer;
	static GL_Sprite* spriteBuffer;

	static int spriteIndex;

	GLsync gSync;

	static std::vector<SpriteObj> spriteList;
	std::vector<Batch> batchList;


	unsigned int VBO, VAO, IBO;
};
