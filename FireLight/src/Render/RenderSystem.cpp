#include "RenderSystem.h"

//RenderBuffer* RenderSystem::FirstBuffer;
//RenderBuffer* RenderSystem::SecondBuffer;
//
//uint32_t RenderSystem::BufferIndex = 1;
//
//
//
//std::vector<Batch> RenderSystem::m_batchs;
//std::vector<RenderObject> RenderSystem::m_renderObjects;
//
//
EntityHandler* RenderSystem::m_camera;
std::vector<SpriteObj> RenderSystem::spriteList;
//
//EntityHandler* RenderSystem::testHandle;
//
//glm::mat4 RenderSystem::projection;
//glm::mat4 RenderSystem::orientation;
//
//
//uint32_t RenderSystem::numberOfBatch = 0;
//uint32_t RenderSystem::numberOfObjects = 0;



GL_Sprite* RenderSystem::spriteBuffer;
int RenderSystem::spriteIndex = 0;

RenderSystem::RenderSystem()
{


}


void RenderSystem::Init()
{
	//size_t renderBuffer = (sizeof(GL_Sprite) * 6) *150000;
	//spriteBuffer = new GL_Sprite();
	//spriteBuffer = (GL_Sprite*)malloc(RenderBufferSize);


	Resource::LoadTexture("Resources/Sprites/Sprites.png", true, "sprite");
	Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");

	GLbitfield fMap = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT;

	GLbitfield fCreate = fMap | GL_DYNAMIC_STORAGE_BIT;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferStorage(GL_ARRAY_BUFFER, BUFFER_SIZE, nullptr, fCreate);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	renderBuffer = (GL_Sprite*)glMapBufferRange(GL_ARRAY_BUFFER, 0, BUFFER_SIZE, fMap);
	spriteBuffer = renderBuffer;

	World::addEngineSystem(new Camera2DSystem());
	World::addEngineSystem(new SpriteRenderSystem());


	//for (int i = 0; i < 500000; i++)
	//{
	//	glm::vec2 position(RandomNumber::Range(-100, 100), RandomNumber::Range(-100, 100));
	//	glm::vec2 size(1, 1);
	//	addSprite(position, size, 0.0f, 4.0f, 8.0f, 16.0f, 16.0f, Resource::getTexture("sprite"));
	//}



	/*unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	float vertices[]
	{
		//Position			//UV
		0.5f, 0.5f, 0.0f,  1.0f, 0.0f,
		0.5f, -0.5f, 0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f,
		-0.5f, 0.5f, 0.0f,  0.0f, 0.0f,
	};

	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/


}


void RenderSystem::addSprite(glm::vec2 pos, glm::vec2 size, float rot, float offX, float offY, float collum, float row, Texture texture)
{
	//SpriteObj tempObj(tran->Position, tran->Scale, tran->Rotation, sprite->OffsetX, sprite->OffsetY, sprite->Rows, sprite->Collums, shader, texture);
	//priteList.push_back(tempObj);



	//glm::vec2 m_pos = pos;
	//glm::vec2 m_size = size;
	float m_rot = rot;
	float cosine = cos(rot);
	float sine = sin(rot);



	glm::vec2 offset = glm::vec2(offX, offY);

	glm::vec2 grid = glm::vec2(collum, row);

	glm::vec2 base_scale = glm::vec2(texture.Width / grid.x, texture.Height / grid.y);

	float x = ((-0.5f * (size.x * base_scale.x)) * cosine + (0.5f * (size.y * base_scale.y)) * sine);
	float y = ((-0.5f * (size.x * base_scale.x)) * sine - (0.5f * (size.y * base_scale.y)) * cosine);

	GL_Sprite* buffer = &spriteBuffer[spriteIndex];


	buffer->vertex = glm::vec3(pos.x + (x), pos.y + (y), 0);
	buffer->uv = glm::vec2(offset.x / grid.x, (1.0f + offset.y) / grid.y);
	buffer++;

	x = ((-0.5f * (size.x * base_scale.x)) * cosine - (0.5f * (size.y * base_scale.y)) * sine);
	y = ((-0.5f * (size.x * base_scale.x)) * sine + (0.5f * (size.y * base_scale.y)) * cosine);

	buffer->vertex = glm::vec3(pos.x + (x), pos.y + (y), 0);
	buffer->uv = glm::vec2(offset.x / grid.x, offset.y / grid.y);
	buffer++;

	x = ((0.5f * (size.x * base_scale.x)) * cosine - (0.5f * (size.y * base_scale.y)) * sine);
	y = ((0.5f * (size.x * base_scale.x)) * sine + (0.5f * (size.y * base_scale.y)) * cosine);

	buffer->vertex = glm::vec3(pos.x + (x), pos.y + (y), 0);
	buffer->uv = glm::vec2((1.0f + offset.x) / grid.x, offset.y / grid.y);
	buffer++;

	x = ((0.5f * (size.x * base_scale.x)) * cosine - (0.5f * (size.y * base_scale.y)) * sine);
	y = ((0.5f * (size.x * base_scale.x)) * sine + (0.5f * (size.y * base_scale.y)) * cosine);

	buffer->vertex = glm::vec3(pos.x + (x), pos.y + (y), 0);
	buffer->uv = glm::vec2((1.0f + offset.x) / grid.x, offset.y / grid.y);
	buffer++;

	x = ((0.5f * (size.x * base_scale.x)) * cosine + (0.5f * (size.y * base_scale.y)) * sine);
	y = ((0.5f * (size.x * base_scale.x)) * sine - (0.5f * (size.y * base_scale.y)) * cosine);

	buffer->vertex = glm::vec3(pos.x + (x), pos.y + (y), 0);
	buffer->uv = glm::vec2((1.0f + offset.x) / grid.x, (1.0f + offset.y) / grid.y);
	buffer++;

	x = ((-0.5f * (size.x * base_scale.x)) * cosine + (0.5f * (size.y * base_scale.y)) * sine);
	y = ((-0.5f * (size.x * base_scale.x)) * sine - (0.5f * (size.y * base_scale.y)) * cosine);

	buffer->vertex = glm::vec3(pos.x + (x), pos.y + (y), 0);
	buffer->uv = glm::vec2((0.0f + offset.x) / grid.x, (1.0f + offset.y) / grid.y);
	buffer++;

	spriteIndex += 6;


}

bool RenderSystem::compareTexture(const SpriteObj &a, const SpriteObj &b)
{
	return ((a.m_texture.ID) > (b.m_texture.ID));
}

void RenderSystem::GenerateBatch()
{

	/*int begin = 0;

	for (uint32_t i = 0; i < spriteList.size(); i++)
	{

		if (i+1 != spriteList.size())
		{
			if(spriteList[i].m_texture.ID != spriteList[i+1].m_texture.ID)
			{
				Batch tempBathc;
				tempBathc.m_texture = spriteList[i].m_texture;
				tempBathc.m_shader = spriteList[i].m_shader;
				tempBathc.m_begin = begin;
				tempBathc.m_end = i;
				batchList.push_back(tempBathc);
				begin = i;
			}
		}
		else
		{
			Batch tempBathc;
			tempBathc.m_texture = spriteList[i].m_texture;
			tempBathc.m_shader = spriteList[i].m_shader;
			tempBathc.m_begin = begin;
			tempBathc.m_end = i;
			batchList.push_back(tempBathc);
		}

	}*/

	//FirstBuffer->Begin();

	//std::cout << m_renderObjects[0].sprite[0].uv.x << std::endl;
	
	//FirstBuffer->UpdateData(m_renderObjects[0].sprite);
	//FirstBuffer->End();

	//std::stable_sort(m_renderObjects.begin(),m_renderObjects.end(), compareTexture);

	/*GLuint CurrentBatchIndex = 0;

	for (uint32_t i = 0; i < m_renderObjects.size(); i++)
	{
		FirstBuffer->UpdateData(m_renderObjects[i].sprite);

		//Generating Batch
		if ((i + 1) == m_renderObjects.size())
		{
			m_batchs.push_back(Batch(CurrentBatchIndex * sizeof(GL_Sprite) * 6, (i + 1) * sizeof(GL_Sprite) * 6, m_renderObjects[i].m_material));
			CurrentBatchIndex = i + 1;
		}
		else
		{
			if (m_renderObjects[i].m_material.m_texture.ID != m_renderObjects[i + 1].m_material.m_texture.ID)
			{
				m_batchs.push_back(Batch(CurrentBatchIndex * sizeof(GL_Sprite) * 6, (i + 1) * sizeof(GL_Sprite) * 6, m_renderObjects[i].m_material));
				CurrentBatchIndex = i + 1;
			}
		}
	}*/
}


void RenderSystem::GenerateBuffer()
{

	for (int i = 0; i < 150000; i++)
	{
		glm::vec2 position(RandomNumber::Range(-100, 100), RandomNumber::Range(-100, 100));
		glm::vec2 size(1, 1);
		addSprite(position, size, 0.0f, 4.0f, 8.0f, 16.0f, 16.0f, Resource::getTexture("sprite"));
	}


	/*for (uint32_t i = 0; i < spriteList.size(); i++)
	{
		SpriteObj& spTemp = spriteList[i];

		float cosine = cos(spTemp.m_rot);
		float sine = sin(spTemp.m_rot);


		glm::vec2 base_scale = glm::vec2(spTemp.m_texture.Width / spTemp.m_Collums, spTemp.m_texture.Height / spTemp.m_Rows);

		float x = ((-0.5f * (spTemp.m_scale.x * base_scale.x)) * cosine + (0.5f * (spTemp.m_scale.y * base_scale.y)) * sine);
		float y = ((-0.5f * (spTemp.m_scale.x * base_scale.x)) * sine - (0.5f * (spTemp.m_scale.y * base_scale.y)) * cosine);

		spriteBuffer[spriteIndex].vertex = glm::vec3(spTemp.m_position.x + (x), spTemp.m_position.y + (y), 0);
		spriteBuffer[spriteIndex].uv = glm::vec2(spTemp.m_OffsetX / spTemp.m_Collums, (1.0f + spTemp.m_OffsetY) / spTemp.m_Rows);


		x = ((-0.5f * (spTemp.m_scale.x * base_scale.x)) * cosine - (0.5f * (spTemp.m_scale.y * base_scale.y)) * sine);
		y = ((-0.5f * (spTemp.m_scale.x * base_scale.x)) * sine + (0.5f * (spTemp.m_scale.y * base_scale.y)) * cosine);

		spriteBuffer[spriteIndex + 1].vertex = glm::vec3(spTemp.m_position.x + (x), spTemp.m_position.y + (y), 0);
		spriteBuffer[spriteIndex + 1].uv = glm::vec2(spTemp.m_OffsetX / spTemp.m_Collums, spTemp.m_OffsetY / spTemp.m_Rows);


		x = ((0.5f * (spTemp.m_scale.x * base_scale.x)) * cosine - (0.5f * (spTemp.m_scale.y * base_scale.y)) * sine);
		y = ((0.5f * (spTemp.m_scale.x * base_scale.x)) * sine + (0.5f * (spTemp.m_scale.y * base_scale.y)) * cosine);

		spriteBuffer[spriteIndex + 2].vertex = glm::vec3(spTemp.m_position.x + (x), spTemp.m_position.y + (y), 0);
		spriteBuffer[spriteIndex + 2].uv = glm::vec2((1.0f + spTemp.m_OffsetX) / spTemp.m_Collums, spTemp.m_OffsetY / spTemp.m_Rows);

		x = ((0.5f * (spTemp.m_scale.x * base_scale.x)) * cosine - (0.5f * (spTemp.m_scale.y * base_scale.y)) * sine);
		y = ((0.5f * (spTemp.m_scale.x * base_scale.x)) * sine + (0.5f * (spTemp.m_scale.y * base_scale.y)) * cosine);

		spriteBuffer[spriteIndex + 3].vertex = glm::vec3(spTemp.m_position.x + (x), spTemp.m_position.y + (y), 0);
		spriteBuffer[spriteIndex + 3].uv = glm::vec2((1.0f + spTemp.m_OffsetX) / spTemp.m_Collums, spTemp.m_OffsetY / spTemp.m_Rows);

		x = ((0.5f * (spTemp.m_scale.x * base_scale.x)) * cosine + (0.5f * (spTemp.m_scale.y * base_scale.y)) * sine);
		y = ((0.5f * (spTemp.m_scale.x * base_scale.x)) * sine - (0.5f * (spTemp.m_scale.y * base_scale.y)) * cosine);

		spriteBuffer[spriteIndex + 4].vertex = glm::vec3(spTemp.m_position.x + (x), spTemp.m_position.y + (y), 0);
		spriteBuffer[spriteIndex + 4].uv = glm::vec2((1.0f + spTemp.m_OffsetX) / spTemp.m_Collums, (1.0f + spTemp.m_OffsetY) / spTemp.m_Rows);

		x = ((-0.5f * (spTemp.m_scale.x * base_scale.x)) * cosine + (0.5f * (spTemp.m_scale.y * base_scale.y)) * sine);
		y = ((-0.5f * (spTemp.m_scale.x * base_scale.x)) * sine - (0.5f * (spTemp.m_scale.y * base_scale.y)) * cosine);

		spriteBuffer[spriteIndex + 5].vertex = glm::vec3(spTemp.m_position.x + (x), spTemp.m_position.y + (y), 0);
		spriteBuffer[spriteIndex + 5].uv = glm::vec2((0.0f + spTemp.m_OffsetX) / spTemp.m_Collums, (1.0f + spTemp.m_OffsetY) / spTemp.m_Rows);

		//spriteIndex += 6;

	}*/
}

void RenderSystem::setCamera(EntityHandler* camera)
{
	m_camera = camera;
}


 void RenderSystem::Draw()
{
	 glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)), glm::vec3(1, 1, 1));
	 model = glm::rotate(model, 0.0f, glm::vec3(0, 0, 1));


	 //std::cout << "batch: " << batchList.size() << std::endl;
	 //std::cout << "sprite: " << spriteList.size() << std::endl;
		
	Resource::getTexture("sprite").Bind();


	Resource::getShader("shader").Use();
	Resource::getShader("shader").SetMatrix4("model", model, false);
	Resource::getShader("shader").SetMatrix4("projection", m_camera->get_Component<Camera2D>()->projection, false);
	Resource::getShader("shader").SetVector2f("row", glm::vec2(1, 1), false);
	Resource::getShader("shader").SetVector2f("offset", glm::vec2(0, 0), false);

	glDrawArrays(GL_TRIANGLES, 0, spriteIndex);
	

	
	spriteBuffer = renderBuffer;
	spriteIndex = 0;
	
	LockBuffer();


	/* Resource::getTexture("sprite").Bind();


	 Resource::getShader("shader").Use();
	 Resource::getShader("shader").SetMatrix4("model", model, false);
	 Resource::getShader("shader").SetMatrix4("projection", m_camera->get_Component<Camera2D>()->projection, false);
	 Resource::getShader("shader").SetVector2f("row", glm::vec2(1, 1), false);
	 Resource::getShader("shader").SetVector2f("offset", glm::vec2(0, 0), false);*/


	 ////std::cout << spriteIndex << std::endl;

	 //glDrawArrays(GL_TRIANGLES, 0, (GLsizei)(spriteIndex));

	 //spriteList.clear();
	 //batchList.clear();


	 //***** OLD BATHC SYSTEM *****
	/*glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,0.0f)), glm::vec3(1, 1, 1));
	model = glm::rotate(model, 0.0f, glm::vec3(0, 0, 1));
	
	 numberOfBatch = m_batchs.size();
	 numberOfObjects = m_renderObjects.size();

	 for (uint32_t i = 0; i < m_batchs.size(); i++)
	 {
		FirstBuffer->beginDraw();
		m_batchs[i].Use();
		m_batchs[i].m_material.m_shader.SetMatrix4("model", model, false);
		m_batchs[i].m_material.m_shader.SetMatrix4("projection", m_camera->get_Component<Camera2D>()->projection, false);

		m_batchs[i].m_material.m_shader.SetVector2f("row", glm::vec2(1, 1), false);
		m_batchs[i].m_material.m_shader.SetVector2f("offset", glm::vec2(0, 0), false);
		FirstBuffer->Draw(m_batchs[i].m_begin, m_batchs[i].m_end);
		FirstBuffer->endDraw();
	 }
	 //BufferIndex *= -1;
	 m_batchs.clear();
	 m_renderObjects.clear();*/
}


RenderSystem::~RenderSystem()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	//delete(renderBuffer);
	//delete(spriteBuffer);
	//glDeleteBuffers(1, &EBO);
}
