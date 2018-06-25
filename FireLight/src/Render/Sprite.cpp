#include "Sprite.h"



Sprite::Sprite()
{
}

void Sprite::init()
{
	float vertices[]
	{
		//Position			//UV
		0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		1.0f, -1.0f, 0.0f,  1.0f, 0.0f,

		0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
		1.0f, -1.0f, 0.0f,  1.0f, 0.0f
	};



	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	m_vbo.Gen(vertices, sizeof(vertices), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	m_vbo.Unbind();
	glBindVertexArray(0);
}


void Sprite::Draw(Camera *camera)
{
	model = glm::scale(glm::translate(glm::mat4(1.0f), this->get_world_position()), this->get_world_scale());
	model = glm::rotate(model, this->get_local_rotation(), glm::vec3(0, 0, 1));

	ResourceManager::GetShader("2D_shader").SetMatrix4("model", model, false);
	ResourceManager::GetShader("2D_shader").SetMatrix4("view", camera->get_viewMatrix(), false);
	ResourceManager::GetShader("2D_shader").SetMatrix4("projection", camera->get_projectionMatrix(), false);

	ResourceManager::GetShader("2D_shader").SetVector2f("row", glm::vec2(1.0f,1.0f), false);
	ResourceManager::GetShader("2D_shader").SetVector2f("offset", glm::vec2(0.0f, 0.0f), false);

	/*

	row;
	 offset
	 
	 */


	//  ResourceManager::GetShader("shader").SetVector2f("offset", glm::vec2(0,0), false); 
	//cout << "Draw" << endl;
	ResourceManager::GetTexture("sprite").Bind();
	ResourceManager::GetShader("2D_shader").Use();


	glBindVertexArray(VAO);



	//glDrawElements(GL_TRIANGLES,100 * 100 * 6, GL_UNSIGNED_INT, 0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}


Sprite::~Sprite()
{
}
