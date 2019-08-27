#include "RenderManager.h"


glm::mat4 RenderManager::m_projection;


RenderManager::RenderManager()
{
}







void RenderManager::Init()
{

	Resource::LoadShader("Resources/Shaders/3Dtest.vert", "Resources/Shaders/3Dtest.frag", NULL, "3D_shader");
	Resource::LoadTexture("Resources/Texture/tex.jpg", true, "texture");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);


	float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};


	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//m_projection = glm::perspective(glm::radians(60.0f), (float)FL::Window::getWidth() / (float)FL::Window::getHeight(), 0.1f, 100.0f);

	/*view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0,0,-3.0));
	glm::mat4 yaw = glm::mat4(1.0f);
	glm::mat4 pitch = glm::mat4(1.0f);
	glm::mat4 roll = glm::mat4(1.0f);

	yaw = glm::rotate(yaw, glm::radians(30.0f), glm::vec3(1, 0, 0));
	pitch = glm::rotate(pitch, glm::radians(0.0f), glm::vec3(0, 1, 0));
	roll = glm::rotate(roll, glm::radians(0.0f), glm::vec3(0, 0, 1));

	glm::mat4 rotation = roll * pitch * yaw;

	view *= rotation;*/
	//view = glm::rotate(view, glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//view = glm::rotate(view, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	//view = glm::rotate(view, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	//m_projection *= view;
	model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), glm::vec3(10, 0.5, 10));
	/*glm::mat4 orientation;

	orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 0, 1));

	m_projection *= orientation;
	m_projection = glm::translate(m_projection, glm::vec3(0.0f, 0.0f, -3.0));*/

	World::addEngineSystem(new Camera3DSystem());
}

void RenderManager::Debug()
{

}

void RenderManager::Draw()
{

	model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), glm::vec3(10, 0.5, 10));

	Texture texture = Resource::getTexture("texture");
	Shader shader = Resource::getShader("3D_shader");

	texture.Bind();

	shader.Use();
	shader.SetMatrix4("projection", m_projection);
	shader.SetMatrix4("model", model);

	glDrawArrays(GL_TRIANGLES, 0, 36);


	model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 1, 0)), glm::vec3(1, 1, 1));

	shader.SetMatrix4("projection", m_projection);
	shader.SetMatrix4("model", model);

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void RenderManager::Close()
{

}



RenderManager::~RenderManager()
{
}
