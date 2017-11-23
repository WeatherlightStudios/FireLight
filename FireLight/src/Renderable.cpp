#include "Renderable.h"
#include <GL\gl3w.h> 
#include "Utility\ResourceManager.h"
#include "SimpleRenderSystem.h"
#include <iostream>

Renderable::Renderable()
{

}

void Renderable::init()
{
	
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	vertex_buffer m_buffer[6];

	m_buffer[0].position = glm::vec3(0.5,0.5,0);
	m_buffer[0].color = m_color;
	m_buffer[0].uv = glm::vec2(1.0,0.0);
	m_buffer[1].position = glm::vec3(0.5, -0.5, 0);
	m_buffer[1].color = m_color;
	m_buffer[1].uv = glm::vec2(1.0, 1.0);
	m_buffer[2].position = glm::vec3(-0.5, -0.5, 0);
	m_buffer[2].color = m_color;
	m_buffer[2].uv = glm::vec2(0.0, 1.0);
	m_buffer[3].position = glm::vec3(-0.5, -0.5, 0);
	m_buffer[3].color = m_color;
	m_buffer[3].uv = glm::vec2(0.0, 1.0);
	m_buffer[4].position = glm::vec3(-0.5, 0.5, 0);
	m_buffer[4].color = m_color;
	m_buffer[4].uv = glm::vec2(0.0, 0.0);
	m_buffer[5].position = glm::vec3(0.5, 0.5, 0);
	m_buffer[5].color = m_color;
	m_buffer[5].uv = glm::vec2(1.0, 0.0);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_buffer), m_buffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);


	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Renderable::set_texture(std::string texture)
{
	m_texture = texture;
}
void Renderable::set_texture_offset(glm::vec2 offset)
{
	m_offset = offset;
}

void Renderable::set_texture_row(glm::vec2 rows)
{
	m_rows = rows;
}


void Renderable::Render(Camera cam)
{
	model = glm::scale(glm::translate(glm::mat4(1.0f), this->get_world_position()), this->get_world_scale());
	//model = glm::scale(glm::translate(glm::mat4(1.0f), this->get_world_position()), this->get_world_scale());
	//model = glm::translate(glm::mat4(1.0f), m_position);

	ResourceManager::GetShader("shader").SetMatrix4("model", model, false);
	ResourceManager::GetShader("shader").SetMatrix4("view", cam.get_viewMatrix(), false);
	ResourceManager::GetShader("shader").SetMatrix4("projection", cam.get_projectionMatrix(), false);
	ResourceManager::GetShader("shader").SetVector2f("row", m_rows, false);
	ResourceManager::GetShader("shader").SetVector2f("offset", m_offset, false);
//	ResourceManager::GetShader("shader").SetVector2f("offset", glm::vec2(0,0), false);

	ResourceManager::GetShader("shader").Use();
	ResourceManager::GetTexture(m_texture).Bind();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);

}


Renderable::~Renderable()
{
}
