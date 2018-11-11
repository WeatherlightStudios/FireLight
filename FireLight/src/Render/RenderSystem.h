#pragma once

#include <glm/glm.hpp>
#include <GL/gl3w.h>

#include "../Core/ECS/Components/Transform.h"
#include "../Core/ECS/Components/Sprite.h"

#include "../Utility/Resource.h"

#include "../Core/ECS/Systems/Camera2DSystem.h";
#include "../Core/ECS/Systems/SpriteRenderSystem.h";
#include "../Core/ECS/World.h";

#include <vector>
#include <cstdlib>
#include <algorithm>


#include "RenderBuffer.h"
#include "Material.h"

//struct GL_Sprite
//{
//	glm::vec3 vertex;
//	glm::vec2 uv;
//};

struct RenderObject
{
	RenderObject(Material material) : 
		 m_material(material)
	{

	}
	GL_Sprite sprite[6];
	Material m_material;
};


struct Batch
{
	Batch(GLuint begin, GLuint end, Material material) :
		m_begin(begin), m_end(end), m_material(material)
	{

	}

	void Use() {
		m_material.m_texture.Bind();
		m_material.m_shader.Use();
	}

	GLuint m_begin;
	GLuint m_end;
	Material m_material;
};



class RenderSystem
{
public:
	RenderSystem();

	static void Init();

	static void addSprite(Transform* tran, Sprite* sprite, Shader shader, Texture texture);

	static void GenerateBatch();

	static bool compareTexture(const RenderObject &a,const  RenderObject &b);

	static void setCamera(EntityHandler* camera);

 	static void Draw();



	static uint32_t getNumberOfObjects() { return numberOfObjects; }
	static uint32_t getNumberOfBatch() { return numberOfBatch; }

	~RenderSystem();

private:
	
	static RenderBuffer* FirstBuffer;
	static RenderBuffer* SecondBuffer;

	static uint32_t BufferIndex;

	static glm::mat4 projection;
	static glm::mat4 orientation;

	static EntityHandler* m_camera;


	static std::vector<Batch> m_batchs;
	static std::vector<RenderObject> m_renderObjects;


	static uint32_t numberOfBatch;
	static uint32_t numberOfObjects;

};
