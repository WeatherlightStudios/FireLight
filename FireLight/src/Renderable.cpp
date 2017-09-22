#include "Renderable.h"
#include <GL\gl3w.h> 
#include "Utility\ResourceManager.h"


Renderable::Renderable()
{

}

void Renderable::Init()
{
	m_position = glm::vec3(0, 0, 0);
	//model = glm::translate(model, glm::vec3(0,0,0));
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

}

void Renderable::gen_quad()
{
	
	vertex_buffer m_buffer[6];

	m_buffer[0].position = glm::vec3(0.5,0.5,0);
	m_buffer[0].color = glm::vec3(0, 0, 0);
	m_buffer[1].position = glm::vec3(0.5, -0.5, 0);
	m_buffer[1].color = glm::vec3(0, 0, 0);
	m_buffer[2].position = glm::vec3(-0.5, -0.5, 0);
	m_buffer[2].color = glm::vec3(0, 0, 0);
	m_buffer[3].position = glm::vec3(-0.5, -0.5, 0);
	m_buffer[3].color = glm::vec3(0, 0, 0);
	m_buffer[4].position = glm::vec3(-0.5, 0.5, 0);
	m_buffer[4].color = glm::vec3(0, 0, 0);
	m_buffer[5].position = glm::vec3(0.5, 0.5, 0);
	m_buffer[5].color = glm::vec3(0, 0, 0);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_buffer), m_buffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void Renderable::gen_triangle()
{

	vertex_buffer m_buffer[3];

	m_buffer[0].position = glm::vec3(0.5, 0.5, 0);
	m_buffer[0].color = glm::vec3(0.5, 0.5, 0);
	m_buffer[1].position = glm::vec3(0, 0.5, 0);
	m_buffer[1].color = glm::vec3(0, 0, 0);
	m_buffer[2].position = glm::vec3(-0.5, -0.5, 0);
	m_buffer[2].color = glm::vec3(0, 0, 0);


	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_buffer), m_buffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Renderable::set_trasform(glm::vec3 transform)
{
	m_position = transform;
}
void Renderable::set_scale(glm::vec3 scale)
{
	m_scale = scale;
}

void Renderable::translate(glm::vec3 transform)
{
	m_position += transform;
}
void Renderable::set_color(glm::vec3 color)
{
	m_color = color;
}
void Renderable::scale(glm::vec3 scale)
{
	m_scale += scale;
}


void Renderable::gen_circle()
{

	vertex_buffer m_buffer[3 * 360];

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_buffer), m_buffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
 
void Renderable::Render(Camera cam)
{
	model = glm::scale(glm::translate(glm::mat4(1.0f), m_position), m_scale);
	//model = glm::translate(glm::mat4(1.0f), m_position);

	FL::ResourceManager::getShader("shader").SetMatrix4("model", model, false);
	FL::ResourceManager::getShader("shader").SetMatrix4("view", cam.get_viewMatrix(), false);
	FL::ResourceManager::getShader("shader").SetMatrix4("projection", cam.get_projectionMatrix(), false);

	FL::ResourceManager::getShader("shader").Use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);

}


Renderable::~Renderable()
{
}
