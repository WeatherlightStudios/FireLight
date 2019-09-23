#include "Simple2DRenderSystem.h"

#include <iostream>

Simple2DRenderSystem::Simple2DRenderSystem()
{
}

void Simple2DRenderSystem::Init()
{

	Resource::LoadShader("Resources/Shaders/2D_shader.vert","Resources/Shaders/2D_shader.frag", NULL, "shader");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLSprite) * 4, NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	

	GLuint* indices = new GLuint[INDEX_BUFFER_SIZE];

	int offset = 0;
	for (int i = 0; i < INDEX_BUFFER_SIZE; i += 6)
	{
		indices[i] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;

		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 3;
		indices[i + 5] = offset + 0;

		offset += 4;
	}


	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE * sizeof(GLuint), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


	projection = glm::ortho(-800.0f, 800.0f,-600.0f, 600.0f,0.001f,1000.0f); 
	projection = glm::translate(projection, glm::vec3(0, 0, -3));
								 
	//model = glm::translate(glm::mat4(10.0f), glm::vec3(0,0,0));

}

void Simple2DRenderSystem::Begin()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	m_spriteBuffer = (GLSprite*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}




//Need optimization
void Simple2DRenderSystem::SubmitSprite(Transform* transform, Sprite* sprite)
{
	//auto texture = Resource::getTexture(sprite->m_texture); //<- this is slow but it work!

	float sizeX = (sprite->m_texture.Width / sprite->m_row.x) * transform->GetScale().x;
	float sizeY = (sprite->m_texture.Height / sprite->m_row.y) * transform->GetScale().x;


	glm::vec3 vertexPos(transform->GetPosition().x, transform->GetPosition().y, 0);


	m_spriteBuffer->vertex = glm::vec3(vertexPos.x - sizeX, vertexPos.y - sizeY, 1);
	m_spriteBuffer->uv = glm::vec2(sprite->m_offset.x / sprite->m_row.x, (1 + sprite->m_offset.y) / sprite->m_row.y);
	m_spriteBuffer++;

	m_spriteBuffer->vertex = glm::vec3(vertexPos.x - sizeX, vertexPos.y + sizeY, 1);
	m_spriteBuffer->uv = glm::vec2(sprite->m_offset.x / sprite->m_row.x, sprite->m_offset.y / sprite->m_row.y);
	m_spriteBuffer++;

	m_spriteBuffer->vertex = glm::vec3(vertexPos.x + sizeX, vertexPos.y +  sizeY, 1);
	m_spriteBuffer->uv = glm::vec2((1 + sprite->m_offset.x) / sprite->m_row.x, sprite->m_offset.y / sprite->m_row.y);
	m_spriteBuffer++;

	m_spriteBuffer->vertex = glm::vec3(vertexPos.x + sizeX, vertexPos.y - sizeY, 1);
	m_spriteBuffer->uv = glm::vec2((1 + sprite->m_offset.x) / sprite->m_row.x, (1 + sprite->m_offset.y) / sprite->m_row.y);
	m_spriteBuffer++;

	m_IndexCounter += 6;

}


void Simple2DRenderSystem::End()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Simple2DRenderSystem::Flush()
{
	auto shader = Resource::getShader("shader");
	auto texture = Resource::getTexture("sprite");


	model = glm::translate(glm::mat4(1.0f), glm::vec3(0,0, 0));
	model = glm::scale(model, glm::vec3(1, 1, 1));
	model = glm::rotate(model, 0.0f, glm::vec3(0, 0, 1));


	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,IBO);

	texture.Bind();
	shader.Use();

	shader.SetMatrix4("projection", projection);
	shader.SetMatrix4("model", model);

	glDrawElements(GL_TRIANGLES, m_IndexCounter, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	m_IndexCounter = 0;
}



//void Simple2DRenderSystem::Draw(Sprite* sp)
//{
//	/*auto shader = Resource::getShader("shader");
//	auto texture = Resource::getTexture("sprite");
//
//	glm::vec2 row = sp->m_row;
//	glm::vec2 offset = sp->m_offset;
//
//	model = glm::translate(glm::mat4(10.0f), glm::vec3(sp->m_position, 0));
//	model = glm::scale(model, glm::vec3(sp->m_scale + glm::vec2(texture.Width / row.x, texture.Height / row.y), 1));
//	model = glm::rotate(model, sp->m_rotation, glm::vec3(0, 0, 1));
//
//
//
//	texture.Bind();
//	shader.Use();
//
//	shader.SetMatrix4("projection", projection);
//	shader.SetMatrix4("model", model);
//	shader.SetVector2f("row", row);
//	shader.SetVector2f("offset", offset);
//
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//*/
//}


Simple2DRenderSystem::~Simple2DRenderSystem()
{
}
