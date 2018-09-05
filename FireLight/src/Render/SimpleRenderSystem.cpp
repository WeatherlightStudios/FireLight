#include "SimpleRenderSystem.h"

//Camera* SimpleRenderSystem::m_camera;


SimpleRenderSystem::SimpleRenderSystem()
{

}


void SimpleRenderSystem::Init()
{

}


void SimpleRenderSystem::Update()
{

}

SimpleRenderSystem::~SimpleRenderSystem()
{

}


//SYSTEMS

RenderSpriteSystem::RenderSpriteSystem(Camera2D* m_current_camera)
{
}



void RenderSpriteSystem::Init()
{
	registerComponent<Transform>();
	registerComponent<Sprite>();
	registerComponent<MeshRender>();
}

void RenderSpriteSystem::Update(std::vector<BaseComponent*> components)
{
	Sprite* sprite = (Sprite*)components[1];
	MeshRender* meshrender = (MeshRender*)components[2];


	glGenVertexArrays(1, &meshrender->VAO);

	glBindVertexArray(meshrender->VAO);

	meshrender->m_vbo.Gen(sprite->vertices, sizeof(*sprite->vertices), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	meshrender->m_vbo.Unbind();
	glBindVertexArray(0);




}

void RenderSpriteSystem::Render(std::vector<BaseComponent*> components)
{
	Transform* transform = (Transform*)components[0];
	MeshRender* meshrender = (MeshRender*)components[2];

	model = glm::scale(glm::translate(glm::mat4(1.0f), this->world_position()), this->world_scale());
	model = glm::rotate(model, this->local_rotation(), glm::vec3(0, 0, 1));

	m_shader.SetMatrix4("model", model, false);
	m_shader.SetMatrix4("projection", camera->getMatrix(), false);

	m_shader.SetVector2f("row", glm::vec2(m_row, m_collum), false);
	m_shader.SetVector2f("offset", glm::vec2(m_offsetX, m_offsetY), false);

	m_texture.Bind();
	m_shader.Use();


	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

}


RenderSpriteSystem::~RenderSpriteSystem()
{
}