#include "2DRenderSystem.h"

std::vector<GLSprite> RenderSystem::m_sprite;


RenderSystem::RenderSystem()
{


}


void RenderSystem::Init()
{




	//Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");
	//Resource::LoadTexture("Resources/Sprites/Sprites.png", true, "sprite");

	GLbitfield fMap = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT ;
	GLbitfield fCreation = fMap | GL_DYNAMIC_STORAGE_BIT;

	//glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VBOtest);

	//glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferStorage(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE, nullptr, fCreation);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3));
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

	World::addEngineSystem(new SpriteRenderSystem());
	World::addEngineSystem(new Camera2DSystem());

}

void RenderSystem::SrotSprites()
{
	std::sort(m_sprite.begin(), m_sprite.end(), sortByTexture);
}


void RenderSystem::CreateBatches()
{
	int begin = 0;
	int count = 0;

	for (uint32_t i = 0; i < m_sprite.size(); i++)
	{

		GLSprite& sprite = m_sprite[i];

		updateBufferSprite(
			sprite.posX,
			sprite.posY,
			sprite.rotatin,
			sprite.zLayer, 
			sprite.texture.Width,
			sprite.texture.Height,
			sprite.scaleX, 
			sprite.scaleY, 
			sprite.offsetX, 
			sprite.offsetY,
			sprite.row, 
			sprite.collum
		);



		count += 6;
		if ((i + 1) != m_sprite.size())
		{
			if (m_sprite[i].texture.ID != m_sprite[i + 1].texture.ID)
			{

				m_batches.push_back(Batch(begin, count, m_sprite[i].texture, m_sprite[i].shader));

				begin = count;
				count = 0;
			}
		}
		else
		{
			m_batches.push_back(Batch(begin, count, m_sprite[i].texture, m_sprite[i].shader));
		}
	}



}

void const RenderSystem::vectorRotation(float x, float y, float rot)
{
	x = x * cos(rot) - y * sin(rot);
	y = x * sin(rot) + y * cos(rot);
}

void RenderSystem::updateBufferSprite(float x, float y, float rotation, int zLayer, int width, int height, float scaleX, float scaleY, float offsetX, float offsetY, int row, int collums)
{
	float positionX = (x - (width / collums)) * scaleX;
	float positionX2 = (x + (width / collums)) * scaleX;
	float positionY = (y - (height / row)) * scaleY;
	float positionY2 = (y + (height / row)) * scaleY;

	float UVx1 = (0 + offsetX) / collums;
	float UVx2 = (1 + offsetX) / collums;

	float UVy1 = (0 + offsetY) / row;
	float UVy2 = (1 + offsetY) / row;



	// **************** FIRST TRIANGLE ***************
	//vertex 0
	current_buffer[0] = positionX;
	current_buffer[1] = positionY2;
	current_buffer[2] = zLayer;
	//color
	current_buffer[3] = UVx1;
	current_buffer[4] = UVy1;

	//vertex 1
	current_buffer[5] = positionX2;
	current_buffer[6] = positionY2;
	current_buffer[7] = zLayer;
	//color
	current_buffer[8] = UVx2;
	current_buffer[9] = UVy1;

	//vertex 2
	current_buffer[10] = positionX2;
	current_buffer[11] = positionY;
	current_buffer[12] = zLayer;
	//color
	current_buffer[13] = UVx2;
	current_buffer[14] = UVy2;


	// **************** SECOND TRIANGLE ***************
	//vertex 0
	current_buffer[15] = positionX2;
	current_buffer[16] = positionY;
	current_buffer[17] = zLayer;
	//color
	current_buffer[18] = UVx2;
	current_buffer[19] = UVy2;

	//vertex 1
	current_buffer[20] = positionX;
	current_buffer[21] = positionY;
	current_buffer[22] = zLayer;
	//color
	current_buffer[23] = UVx1;
	current_buffer[24] = UVy2;

	//vertex 2
	current_buffer[25] = positionX;
	current_buffer[26] = positionY2;
	current_buffer[27] = zLayer;
	//color
	current_buffer[28] = UVx1;
	current_buffer[29] = UVy1;

	current_buffer += 30;
	sprite_index += 6;
}


void RenderSystem::Debug()
{
	
}

 void RenderSystem::Draw()
{
	 glm::mat4 model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), glm::vec3(1, 1, 1));
	 model = glm::rotate(model, 0.0f, glm::vec3(0,0,1));


	
	 for (int i = 0; i < m_batches.size(); i++)
	 {
		 //Texture text = Resource::getTexture("sprite");
		 Shader shader = Resource::getShader(m_batches[i].m_shader);



		 m_batches[i].m_texture.Bind();
		 shader.Use();
		 shader.SetMatrix4("projection", m_projection);
		 shader.SetMatrix4("model", model);
		glDrawArrays(GL_TRIANGLES, m_batches[i].m_begin, m_batches[i].m_count);
	 }

	 sprite_index = 0;
	 current_buffer = buffer;

	 clearBatch();
	 clearSprites();
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
