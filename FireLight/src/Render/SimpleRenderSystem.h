#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H
//external includes
#include <vector>
#include <algorithm>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//internal includes
#include "../Core/ECS/World.h"
#include "../Core/ECS/Components/Camera2D.h"
#include "../Core/ECS/Components/Sprite.h"
#include "../Core/ECS/Components/Transfrom.h"
#include "../Core/ECS/Components/MeshRender.h"

/// <summary>
/// Actual Render System
/// Provide to render stuff on screen
/// </summary>
class SimpleRenderSystem
{
public:
	SimpleRenderSystem();

	void Init();

	void Update();

	~SimpleRenderSystem();
private:
	EntityHandler* Camera;


	VertexBuffer m_vbo;
	IndexBuffer m_ibo;

	glm::mat4 model;

	GLuint VAO;
	GLuint EBO;
};


class RenderSpriteSystem : public System
{
public:
	RenderSpriteSystem(EntityHandler* current_camera);


	void Init();
	void InitEntity(std::vector<BaseComponent*> components);
	void Update(std::vector<BaseComponent*> components);
	void Render(std::vector<BaseComponent*> components);

	~RenderSpriteSystem();

private:

	EntityHandler* m_camera;

};

#endif SIMPLERENDERSYSTEM_H