#include "RenderSystem.h"


RenderSystem::RenderSystem()
{


}


void RenderSystem::Init()
{




	Resource::LoadShader("Resources/Shaders/fast2D.vert", "Resources/Shaders/fast2D.frag", NULL, "shader");
	//Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "2D_shader");
	//Resource::LoadShader("Resources\Shaders\2D_shader.vert", "Resources\Shaders\2D_shader.frag", NULL, "shader2");

	GLbitfield fMap = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT ;
	GLbitfield fCreation = fMap | GL_DYNAMIC_STORAGE_BIT;

	//glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferStorage(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE, nullptr, fCreation);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	buffer = (float*)glMapBufferRange(GL_ARRAY_BUFFER, 0, VERTEX_BUFFER_SIZE, fMap | GL_MAP_UNSYNCHRONIZED_BIT);
	current_buffer = buffer;
	

	m_projection = glm::ortho(-(float)FL::Window::getWidth() / 2.0f, (float)FL::Window::getWidth() / 2.0f, -(float)FL::Window::getHeight() / 2.0f, (float)FL::Window::getHeight() / 2.0f, 0.001f, 1000.0f);


	glm::mat4 orientation;

	orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 0, 1));

	m_projection *= orientation;
	m_projection = glm::translate(m_projection, glm::vec3(0.0f,0.0f, -3.0));




	//m_projection = m_projection * model;

}

void RenderSystem::UpdateBuffer()
{
	for (int i = -353; i < 353; i++)
	{
		for (int k = -353; k < 353; k++)
		{

			float x = 1;
			float y = 1;

			float r = 1;
			float g = 1;
			float b = 1;

			addSprite(i*3,k*3, r,g,b);
		}
	}
}

void RenderSystem::addSprite(float x, float y, int r, int g, int b)
{

	float red = (1.0 / 255) * r;
	float green = (1.0 / 255) * g;
	float blue = (1.0 / 255) * b;

	// **************** FIRST TRIANGLE ***************
	//vertex 0
	current_buffer[0] = x - 1;
	current_buffer[1] = y + 1;
	current_buffer[2] = 0;
	//color
	current_buffer[3] = red;
	current_buffer[4] = green;
	current_buffer[5] = blue;

	//vertex 1
	current_buffer[6] = x + 1;
	current_buffer[7] = y + 1;
	current_buffer[8] = 0;
	//color
	current_buffer[9] = red;
	current_buffer[10] = green;
	current_buffer[11] = blue;


	//vertex 2
	current_buffer[12] = x + 1;
	current_buffer[13] = y - 1;
	current_buffer[14] = 0;
	//color
	current_buffer[15] = red;
	current_buffer[16] = green;
	current_buffer[17] = blue;


	// **************** SECOND TRIANGLE ***************
	//vertex 0
	current_buffer[18] = x + 1;
	current_buffer[19] = y - 1;
	current_buffer[20] = 0;
	//color
	current_buffer[21] = red;
	current_buffer[22] = green;
	current_buffer[23] = blue;

	//vertex 1
	current_buffer[24] = x-1;
	current_buffer[25] = y-1;
	current_buffer[26] = 0;
	//color
	current_buffer[27] = red;
	current_buffer[28] = green;
	current_buffer[29] = blue;

	//vertex 2
	current_buffer[30] = x - 1;
	current_buffer[31] = y + 1;
	current_buffer[32] = 0;
	//color
	current_buffer[33] = red;
	current_buffer[34] = green;
	current_buffer[35] = blue;

	current_buffer += 36;
	sprite_index += 6;
}


void RenderSystem::Debug()
{

}

 void RenderSystem::Draw()
{
	 glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), glm::vec3(1, 1, 1));
	 model = glm::rotate(model, 0.0f, glm::vec3(0,0,1));

	 Shader shader = Resource::getShader("shader");

	 shader.Use();
	 shader.SetMatrix4("projection", m_projection);
	 shader.SetMatrix4("model", model);
	 glDrawArrays(GL_TRIANGLES, 0, sprite_index);
	 sprite_index = 0;
	 current_buffer = buffer;
}

 void RenderSystem::Close()
 {
	 glUnmapBuffer(GL_ARRAY_BUFFER);
	 glDeleteBuffers(1, &VBO);
	 delete(buffer);
 }


RenderSystem::~RenderSystem()
{
}
