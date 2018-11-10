#include "RenderSystem.h"

RenderBuffer* RenderSystem::FirstBuffer;
RenderBuffer* RenderSystem::SecondBuffer;

uint32_t RenderSystem::BufferIndex = 1;



std::vector<Batch> RenderSystem::m_batchs;
std::vector<RenderObject> RenderSystem::m_renderObjects;


EntityHandler* RenderSystem::m_camera;

glm::mat4 RenderSystem::projection;
glm::mat4 RenderSystem::orientation;


RenderSystem::RenderSystem()
{


}


void RenderSystem::Init()
{
	/*size_t RenderBufferSize = (sizeof(GL_Sprite) * 6) *150000;
	spriteBuffer = new GL_Sprite();
	spriteBuffer = (GL_Sprite*)malloc(RenderBufferSize);*/

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


	FirstBuffer = new RenderBuffer();
	SecondBuffer = new RenderBuffer();
	//SecondBuffer->Begin();


	/*glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, RenderBufferSize, NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);*/

	//projection = glm::ortho(-(float)Window::getWidth() / 2.0f, (float)Window::getWidth() / 2.0f, -(float)Window::getWidth() / 2.0f, (float)Window::getWidth() / 2.0f, 0.001f, 10000.0f);
	projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.001f, 10000.0f);

	/*orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 0, 1));

	projection *= orientation;*/
	projection = glm::translate(projection, glm::vec3(0.0f,0.0f, -3.0f));


	//World::addSystem(new Camera2DSystem());
	World::addEngineSystem(new SpriteRenderSystem());

	BufferIndex = 0;

}

void RenderSystem::addSprite(Transform* tran, Sprite* sprite, Shader shader, Texture texture)
{
	RenderObject tempObject(Material(shader, texture));

	glm::vec2 pos = tran->Position;
	glm::vec2 size = tran->Scale;

	glm::vec2 offset = glm::vec2(sprite->OffsetX, sprite->OffsetY);

	glm::vec2 grid = glm::vec2(sprite->Collums, sprite->Rows);

	tempObject.sprite[0].vertex = glm::vec3(pos.x + (-0.5f * size.x), pos.y + (-0.5f * size.y), 0);
	tempObject.sprite[0].uv = glm::vec2(offset.x / grid.x, (1.0f + offset.y) / grid.y);

	tempObject.sprite[1].vertex = glm::vec3(pos.x + (-0.5f * size.x), pos.y + (0.5f * size.y), 0);
	tempObject.sprite[1].uv = glm::vec2(offset.x / grid.x, offset.y / grid.y);

	tempObject.sprite[2].vertex = glm::vec3(pos.x + (0.5f * size.x), pos.y + (0.5f * size.y), 0);
	tempObject.sprite[2].uv = glm::vec2((1.0f + offset.x) / grid.x, offset.y / grid.y);


	tempObject.sprite[3].vertex = glm::vec3(pos.x + (0.5f * size.x), pos.y + (0.5f * size.y), 0);
	tempObject.sprite[3].uv = glm::vec2((1.0f + offset.x) / grid.x, offset.y / grid.y);
	
	tempObject.sprite[4].vertex = glm::vec3(pos.x + (0.5f * size.x), pos.y + (-0.5f * size.y), 0);
	tempObject.sprite[4].uv = glm::vec2((1.0f + offset.x) / grid.x, (1.0f + offset.y) / grid.y);
	
	tempObject.sprite[5].vertex = glm::vec3(pos.x + (-0.5f * size.x), pos.y + (-0.5f * size.y), 0);
	tempObject.sprite[5].uv = glm::vec2((0.0f + offset.x) / grid.x, (1.0f + offset.y) / grid.y);

	m_renderObjects.emplace_back(tempObject);
}

bool RenderSystem::compareTexture(const RenderObject &a, const RenderObject &b)
{
	return ((a.m_material.m_texture.ID) < (b.m_material.m_texture.ID));
}

void RenderSystem::GenerateBatch()
{
	//FirstBuffer->Begin();

	//std::cout << m_renderObjects[0].sprite[0].uv.x << std::endl;
	
	//FirstBuffer->UpdateData(m_renderObjects[0].sprite);
	//FirstBuffer->End();

	std::stable_sort(m_renderObjects.begin(),m_renderObjects.end(), compareTexture);

	GLuint CurrentBatchIndex = 0;

	for (uint32_t i = 0; i < m_renderObjects.size(); i++)
	{
		FirstBuffer->UpdateData(m_renderObjects[i].sprite);
		//Generating Batch
		if ((i + 1) == m_renderObjects.size())
		{
			m_batchs.push_back(Batch(CurrentBatchIndex * 6, (i + 1) * 6, m_renderObjects[i].m_material));
		}
		else
		{
			if (m_renderObjects[i].m_material.m_texture.ID != m_renderObjects[i + 1].m_material.m_texture.ID)
			{
				m_batchs.push_back(Batch(CurrentBatchIndex * 6, i * 6, m_renderObjects[i].m_material));
				CurrentBatchIndex = i;
			}
		}
	}

}

void RenderSystem::setCamera(EntityHandler* camera)
{
	m_camera = camera;
}


 void RenderSystem::Draw()
{
	 glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,0.0f)), glm::vec3(64, 64, 64));
	 model = glm::rotate(model, 0.0f, glm::vec3(0, 0, 1));
	// FirstBuffer->beginDraw();
	//texture.Bind();
	// shader.Use();


	// shader.SetMatrix4("model", model, false);
	// shader.SetMatrix4("projection", projection, false);

	// shader.SetVector2f("row", glm::vec2(1,1), false);
	// shader.SetVector2f("offset", glm::vec2(0,0), false);

	 //FirstBuffer->Draw(0, 6);
	 //FirstBuffer->endDraw();
//	 glBindVertexArray(VAO);
//	/* glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	 spriteBuffer = (GL_Sprite*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
//	 glUnmapBuffer(GL_ARRAY_BUFFER);
//*/
//		//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_Sprite) * sprite_index, spriteBuffer);
//
//		glDrawArrays(GL_TRIANGLES, 0, sprite_index);
//	 glBindVertexArray(0);
	 FirstBuffer->beginDraw();

	 for (uint32_t i = 0; i < m_batchs.size(); i++)
	 {
		 m_batchs[i].Use();


		 m_batchs[i].m_material.m_shader.SetMatrix4("model", model, false);
		 m_batchs[i].m_material.m_shader.SetMatrix4("projection", projection, false);

		 m_batchs[i].m_material.m_shader.SetVector2f("row", glm::vec2(1, 1), false);
		 m_batchs[i].m_material.m_shader.SetVector2f("offset", glm::vec2(0, 0), false);

		 FirstBuffer->Draw(m_batchs[i].m_begin, m_batchs[i].m_end);

	 }
	 FirstBuffer->endDraw();
	 //BufferIndex *= -1;
	 m_batchs.clear();
	 m_renderObjects.clear();
}


RenderSystem::~RenderSystem()
{
}
