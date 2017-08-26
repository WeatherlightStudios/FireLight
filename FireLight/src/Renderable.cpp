#include "Renderable.h"
#include <GL\gl3w.h> 
#include "Utility\ResourceManager.h"


Renderable::Renderable()
{
}

void Renderable::Init()
{


	model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(60.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	float vertices[] = {
		// positions         // colors
		0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom right
		0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		-0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		-0.5f,	0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
	};


	float a = 0;



	for (int y = 0; y < 6000 ; y += 6)
	{
		
		for (int x = 0; x < 6000; x += 6)
		{

			float z_1 = (sin(glm::radians(x + 6.0f) * 5) + sin(glm::radians(y + 6.0f) * 5));
			float z_2 = (sin(glm::radians(x + 0.0f) * 5) + sin(glm::radians(y + 6.0f) * 5));
			float z_3 = (sin(glm::radians(x + 0.0f) * 5) + sin(glm::radians(y + 0.0f) * 5));
			float z_4 = (sin(glm::radians(x + 6.0f) * 5) + sin(glm::radians(y + 0.0f) * 5));


			m_buffer[(x + (y  * 1000)) + 0].position = glm::vec3(1.0 + (x / 6),1.0 + (y / 6), z_1);
			m_buffer[(x + (y  * 1000)) + 0].color = glm::vec3(((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX);
			m_buffer[(x + (y  * 1000)) + 1].position = glm::vec3(1.0 + (x / 6), 0.0 + (y / 6), z_4);
			m_buffer[(x + (y  * 1000)) + 1].color = glm::vec3(((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX);
			m_buffer[(x + (y  * 1000)) + 2].position = glm::vec3(0.0 + (x / 6), 0.0 + (y / 6), z_3);
			m_buffer[(x + (y  * 1000)) + 2].color = glm::vec3(((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX);
			m_buffer[(x + (y  * 1000)) + 3].position = glm::vec3(0.0 + (x / 6), 0.0 + (y / 6), z_3);
			m_buffer[(x + (y  * 1000)) + 3].color = glm::vec3(((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX);
			m_buffer[(x + (y  * 1000)) + 4].position = glm::vec3(0.0 + (x / 6), 1.0 + (y / 6), z_2);
			m_buffer[(x + (y  * 1000)) + 4].color = glm::vec3(((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX);
			m_buffer[(x + (y  * 1000)) + 5].position = glm::vec3(1.0 + (x / 6), 1.0 + (y / 6), z_1);
			m_buffer[(x + (y  * 1000)) + 5].color = glm::vec3(((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX, ((float)rand()) / (float)RAND_MAX);



		}

	}



	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
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

	ResourceManager::getShader("shader").SetMatrix4("model", model, false);


	ResourceManager::getShader("shader").SetMatrix4("view", cam.get_ViewMatrix(), false);
	ResourceManager::getShader("shader").SetMatrix4("projection", cam.getCameraProjection(), false);

	ResourceManager::getShader("shader").Use();
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 1000 * 1000 * 6);

}


Renderable::~Renderable()
{
}
