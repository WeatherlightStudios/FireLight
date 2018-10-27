#include "RenderSystem.h"



GLuint RenderSystem::VBO;
GLuint RenderSystem::VAO;


uint32_t RenderSystem::sprite_index = 0;
GL_Sprite* RenderSystem::spriteBuffer;

EntityHandler* RenderSystem::m_camera;

glm::mat4 RenderSystem::projection;
glm::mat4 RenderSystem::orientation;


RenderSystem::RenderSystem()
{
}


void RenderSystem::Init()
{
	size_t RenderBufferSize = (sizeof(GL_Sprite) * 6) *150000;
	spriteBuffer = new GL_Sprite();
	spriteBuffer = (GL_Sprite*)malloc(RenderBufferSize);

	//float vertices[]
	//{
	//	//Position			//UV
	//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f,
	//	-0.5f, 0.5f, 0.0f,  0.0f, 0.0f,
	//	0.5f, 0.5f, 0.0f,  1.0f, 0.0f,

	//	0.5f, 0.5f, 0.0f,  1.0f, 0.0f,
	//	0.5f, -0.5f, 0.0f,  1.0f, 1.0f,
	//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f
	//};


	//spriteBuffer[0].vertex = glm::vec3(-0.5f, -0.5f, 0);
	//spriteBuffer[0].uv = glm::vec2(0, 1.0f);
	//spriteBuffer[1].vertex = glm::vec3(-0.5f, 0.5f, 0);
	//spriteBuffer[1].uv = glm::vec2(0, 0);
	//spriteBuffer[2].vertex = glm::vec3(0.5f, 0.5f, 0);
	//spriteBuffer[2].uv = glm::vec2(1.0f, 0);
	//spriteBuffer.vertex = glm::vec3(0.5f, 0.5f, 0);
	//spriteBuffer.uv = glm::vec2(1.0f, 0);
	//spriteBuffer++;
	//spriteBuffer.vertex = glm::vec3(0.5f , -0.5f, 0);
	//spriteBuffer.uv = glm::vec2(1.0f, 1.0f);
	//spriteBuffer++;
	//spriteBuffer.vertex = glm::vec3(-0.5f, -0.5f, 0);
	//spriteBuffer.uv = glm::vec2(0.0f, 1.0f);
	//spriteBuffer++;





	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, RenderBufferSize, NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//projection = glm::ortho(-(float)Window::getWidth() / 2.0f, (float)Window::getWidth() / 2.0f, -(float)Window::getWidth() / 2.0f, (float)Window::getWidth() / 2.0f, 0.001f, 10000.0f);
	projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.001f, 10000.0f);

	/*orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 0, 1));

	projection *= orientation;*/
	projection = glm::translate(projection, glm::vec3(0.0f,0.0f, -3.0f));


	//World::addSystem(new Camera2DSystem());
	World::addEngineSystem(new SpriteRenderSystem());

}

void RenderSystem::addSprite(Transform* tran, Sprite* sprite)
{


	glm::vec2 pos = tran->Position;
	glm::vec2 size = tran->Scale;

	glm::vec2 offset = glm::vec2(sprite->OffsetX, sprite->OffsetY);

	glm::vec2 grid = glm::vec2(sprite->Collums, sprite->Rows);

	spriteBuffer[sprite_index].vertex = glm::vec3(pos.x + (-0.5f * size.x), pos.y + (-0.5f * size.y), 0);
	spriteBuffer[sprite_index].uv = glm::vec2(offset.x / grid.x, (1.0f + offset.y) / grid.y);

	spriteBuffer[sprite_index + 1].vertex = glm::vec3(pos.x + (-0.5f * size.x), pos.y + (0.5f * size.y), 0);
	spriteBuffer[sprite_index + 1].uv = glm::vec2(offset.x / grid.x, offset.y / grid.y);

	spriteBuffer[sprite_index + 2].vertex = glm::vec3(pos.x + (0.5f * size.x), pos.y + (0.5f * size.y), 0);
	spriteBuffer[sprite_index + 2].uv = glm::vec2((1.0f + offset.x) / grid.x, offset.y / grid.y);


	spriteBuffer[sprite_index + 3].vertex = glm::vec3(pos.x + (0.5f * size.x), pos.y + (0.5f * size.y), 0);
	spriteBuffer[sprite_index + 3].uv = glm::vec2((1.0f + offset.x) / grid.x, offset.y / grid.y);
	
	spriteBuffer[sprite_index + 4].vertex = glm::vec3(pos.x + (0.5f * size.x), pos.y + (-0.5f * size.y), 0);
	spriteBuffer[sprite_index + 4].uv = glm::vec2((1.0f + offset.x) / grid.x, (1.0f + offset.y) / grid.y);
	
	spriteBuffer[sprite_index + 5].vertex = glm::vec3(pos.x + (-0.5f * size.x), pos.y + (-0.5f * size.y), 0);
	spriteBuffer[sprite_index + 5].uv = glm::vec2((0.0f + offset.x) / grid.x, (1.0f + offset.y) / grid.y);


	//std::cout << "si" << std::endl;

	sprite_index += 6;
}

void RenderSystem::setCamera(EntityHandler* camera)
{
	m_camera = camera;
}


 void RenderSystem::Draw()
{

	/* spriteBuffer[0].vertex = glm::vec3(-0.5f, -0.5f, 0);
	 spriteBuffer[0].uv = glm::vec2(0, 1.0f);
	 spriteBuffer[1].vertex = glm::vec3(-0.5f, 0.5f, 0);
	 spriteBuffer[1].uv = glm::vec2(0, 0);
	 spriteBuffer[2].vertex = glm::vec3(0.5f, 0.5f, 0);
	 spriteBuffer[2].uv = glm::vec2(1.0f, 0);*/

	 glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,0.0f)), glm::vec3(64, 64, 64));
	 model = glm::rotate(model, 0.0f, glm::vec3(0, 0, 1));

	 auto texture = Resource::getTexture("sprite");
	 auto shader = Resource::getShader("2D_shader");

	 texture.Bind();
	 shader.Use();


	 shader.SetMatrix4("model", model, false);
	 shader.SetMatrix4("projection", projection, false);

	 shader.SetVector2f("row", glm::vec2(1,1), false);
	 shader.SetVector2f("offset", glm::vec2(0,0), false);
	 glBindVertexArray(VAO);
	 glBindBuffer(GL_ARRAY_BUFFER, VBO);
	 spriteBuffer = (GL_Sprite*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	 glUnmapBuffer(GL_ARRAY_BUFFER);

		//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_Sprite) * sprite_index, spriteBuffer);

		glDrawArrays(GL_TRIANGLES, 0, sprite_index);
	 glBindVertexArray(0);

	sprite_index = 0;
}


RenderSystem::~RenderSystem()
{
}
