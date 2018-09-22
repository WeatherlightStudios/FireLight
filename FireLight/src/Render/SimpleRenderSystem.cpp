#include "SimpleRenderSystem.h"
#include "../Utility/Resource.h"

//Camera* SimpleRenderSystem::m_camera;


SimpleRenderSystem::SimpleRenderSystem()
{

}


void SimpleRenderSystem::Init()
{
	Camera = World::CreateEntity();

	Camera->add_Component<Transform>(glm::vec3(0,0,0), 0.0f, glm::vec2(1, 1));



	glm::mat4 projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.001f, 10000.0f);
	glm::mat4 orientation;
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 0, 1));
	projection *= orientation;
	projection = glm::translate(projection, glm::vec3(0,0,-3));

	Camera->add_Component<Camera2D>(projection);
	World::addGameSystem(new RenderSpriteSystem(Camera));

	

}


void SimpleRenderSystem::Update()
{
}

SimpleRenderSystem::~SimpleRenderSystem()
{

}


//SYSTEMS

RenderSpriteSystem::RenderSpriteSystem(EntityHandler* m_current_camera)
{
	m_camera = m_current_camera;
}

void RenderSpriteSystem::Init()
{
	registerComponent<Transform>();
	registerComponent<Sprite>();
	registerComponent<MeshRender>();
}


void RenderSpriteSystem::InitEntity(std::vector<BaseComponent*> components)
{

	Sprite* sprite = (Sprite*)components[1];
	MeshRender* meshrender = (MeshRender*)components[2];


	glGenVertexArrays(1, &meshrender->VAO);

	glBindVertexArray(meshrender->VAO);

	meshrender->m_vbo.Gen(sprite->vertices, sizeof(sprite->vertices), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	meshrender->m_vbo.Unbind();
	glBindVertexArray(0);
}

void RenderSpriteSystem::Update(std::vector<BaseComponent*> components)
{

}

void RenderSpriteSystem::Render(std::vector<BaseComponent*> components)
{

	Transform* transform = (Transform*)components[0];
	Sprite* sprite = (Sprite*)components[1];
	MeshRender* meshrender = (MeshRender*)components[2];

	meshrender->model = glm::scale(glm::translate(glm::mat4(1.0f), transform->position), glm::vec3(sprite->m_widht * transform->scale.x, sprite->m_height * transform->scale.y, 1));
	meshrender->model = glm::rotate(meshrender->model, transform->rotation, glm::vec3(0, 0, 1));

	sprite->m_shader.SetMatrix4("model", meshrender->model, false);
	sprite->m_shader.SetMatrix4("projection", m_camera->getComponent<Camera2D>()->m_projection, false);

	sprite->m_shader.SetVector2f("row", glm::vec2(sprite->m_row, sprite->m_collum), false);
	sprite->m_shader.SetVector2f("offset", glm::vec2(sprite->m_offsetX, sprite->m_offsetY), false);

	sprite->m_texture.Bind();
	sprite->m_shader.Use();

	glBindVertexArray(meshrender->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

}


RenderSpriteSystem::~RenderSpriteSystem()
{
}