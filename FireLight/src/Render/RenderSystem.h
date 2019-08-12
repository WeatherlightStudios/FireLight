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

#include "../Utility/Resource.h"

#include <vector>
#include <cstdlib>
#include <algorithm>


struct GL_Sprite
{
	glm::vec3 vertex;
	glm::vec2 uv;
};

#define VERTEX_PER_QUAD 6
#define MAX_SPRITES 160000
#define BUFFER_SIZE (sizeof(GL_Sprite) * 6) * MAX_SPRITES
#define MAX_VERTICES MAX_SPRITES * VERTEX_PER_QUAD



class RenderSystem
{
public:
	RenderSystem();

	void Init();


	//Need ReWork
	static void addSprite(Transform* tran, Sprite* sprite, Shader shader, Texture texture);


	//TODO:: ReWork in AZDO
	void GenerateBatch();

	//mhe?
	//static bool compareTexture(const RenderObject &a,const  RenderObject &b);


	//Need new CameraManager
	static void setCamera(EntityHandler* camera);

	
 	void Draw();

	~RenderSystem();

private:
	

	static EntityHandler* m_camera;


	GL_Sprite* renderBuffer;
	static GL_Sprite* spriteBuffer;

	static int spriteIndex;



	unsigned int VBO, VAO;
};
