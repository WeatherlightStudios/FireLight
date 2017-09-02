#include "Renderable.h"
#include <GL\gl3w.h> 
#include "Utility\ResourceManager.h"


Renderable::Renderable()
{

}

void Renderable::Init()
{
	model = glm::translate(model, glm::vec3(0,0,0));
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

}

void Renderable::generateQuad()
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

void Renderable::generateTriangle()
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



void Renderable::Translate(glm::vec3 transform)
{
	model = glm::translate(model, transform);
}
void Renderable::setColor(glm::vec3 color)
{
	m_color = color;
}
void Renderable::Scale(glm::vec3 scale)
{
	model = glm::scale(model, scale);
}


void Renderable::generateCircle()
{

	vertex_buffer m_buffer[3 * 360];

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_buffer), m_buffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}
 
void Renderable::Render(Camera cam)
{
	FL::ResourceManager::getShader("shader").SetMatrix4("model", model, false);
	FL::ResourceManager::getShader("shader").SetMatrix4("view", cam.get_ViewMatrix(), false);
	FL::ResourceManager::getShader("shader").SetMatrix4("projection", cam.getCameraProjection(), false);

	FL::ResourceManager::getShader("shader").Use();
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6);

}


Renderable::~Renderable()
{
}
