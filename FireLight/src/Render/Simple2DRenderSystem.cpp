#include "Simple2DRenderSystem.h"



Simple2DRenderSystem::Simple2DRenderSystem()
{
}

void Simple2DRenderSystem::Init()
{

	Resource::LoadShader("source/Shaders/2D_shader.vert","source/Shaders/2D_shader.frag", NULL, "shader");
	Resource::LoadTexture("source/Texture/Sprite-Test.png", true, "sprite");



	float vertices[] = {
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f, 1.0f, 1.0f,  // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // bottom left
		-0.5f,  0.5f, 0.0f, 0.0f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};


	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);



	projection = glm::ortho(-800.0f, 800.0f,-600.0f, 600.0f,0.001f,1000.0f); 
	projection = glm::translate(projection, glm::vec3(0, 0, -3));
								 
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0));

}

void Simple2DRenderSystem::Draw(Sprite* sp)
{
	auto shader = Resource::getShader("shader");
	auto texture = Resource::getTexture("sprite");

	glm::vec2 row = sp->m_row;
	glm::vec2 offset = sp->m_offset;

	model = glm::translate(glm::mat4(1.0f), glm::vec3(sp->m_position, 0));
	model = glm::scale(model, glm::vec3(sp->m_scale + glm::vec2(texture.Width / row.x, texture.Height / row.y), 1));
	model = glm::rotate(model, sp->m_rotation, glm::vec3(0, 0, 1));



	texture.Bind();
	shader.Use();

	shader.SetMatrix4("projection", projection);
	shader.SetMatrix4("model", model);
	shader.SetVector2f("row", row);
	shader.SetVector2f("offset", offset);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}


Simple2DRenderSystem::~Simple2DRenderSystem()
{
}
