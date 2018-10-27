#pragma once

#include <glm/glm.hpp>
#include <GL/gl3w.h>

#include "../Core/ECS/Components/Transform.h"
#include "../Core/ECS/Components/Sprite.h"

#include "../Utility/Resource.h"

#include "../Core/ECS/Systems/Camera2DSystem.h";
#include "../Core/ECS/Systems/SpriteRenderSystem.h";
#include "../Core/ECS/World.h";

struct GL_Sprite
{
	glm::vec3 vertex;
	glm::vec2 uv;
};


class RenderSystem
{
public:
	RenderSystem();

	static void Init();
	static void addSprite(Transform* tran,Sprite* sprite);

	static void setCamera(EntityHandler* camera);

 	static void Draw();

	~RenderSystem();

private:
	static GL_Sprite* spriteBuffer;
	static GLuint VBO, VAO;


	static uint32_t sprite_index;
	static glm::mat4 projection;
	static glm::mat4 orientation;

	static EntityHandler* m_camera;

};
