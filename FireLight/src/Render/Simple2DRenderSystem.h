#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H

#include <GL/gl3w.h>
#include "../Utility/Resource.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Components/Sprite.h"
#include "Components/Transform.h"

#include <vector>



struct GLSprite
{
	glm::vec3 vertex;
	glm::vec2 uv;
	float tuid;
};


class Simple2DRenderSystem
{
public:
	Simple2DRenderSystem();


	void Init();

	void Begin();
	void SubmitSprite(Transform* transform, Sprite* sprite);
	void End();

	void Flush();

	//void Draw(Sprite* sp);




	~Simple2DRenderSystem();

private:

	GLSprite* m_spriteBuffer;

	std::vector<GLuint> textures;

	GLuint VAO, VBO, IBO;

	glm::mat4 projection;
	glm::mat4 model;

	GLint tIDs[32];

	uint32_t m_IndexCounter;


	const uint32_t MAX_SPRITES = 100000;
	const size_t VERTEX_SIZE = sizeof(GLSprite);
	const size_t SPRITE_SIZE = VERTEX_SIZE * 4;
	const size_t VERTEX_BUFFER_SIZE = SPRITE_SIZE * MAX_SPRITES;
	const size_t INDEX_BUFFER_SIZE = MAX_SPRITES * 6;


};

#endif