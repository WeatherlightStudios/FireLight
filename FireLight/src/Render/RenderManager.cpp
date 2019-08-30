#include "RenderManager.h"

#include <cmath>

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
	glGenBuffers(1, &EBO);

	const int width = 100;
	const int height = 100;

	float vertex[6 * (width * height)];
	int index[(width - 1) * (height - 1) * 6];


	int vertexIndex = 0;
	int InxIndex = 0;
	int indexI = 0;

	FastNoise myNoise;
	myNoise.SetNoiseType(FastNoise::PerlinFractal);


	//generate the chunk
	for (int z = 0; z < 16; z++)
	{
		for (int x = 0; x < 16; x++)
		{
			float height = myNoise.GetNoise(x, z);

			int blocks = lerp(0, 16, height);

			for (int y = 0; y < 16; y++)
			{
				chunk[x][y][z] = 1;
			}
		}
	}



	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{

			float height = myNoise.GetNoise(x, y);

			float base = (1.0f / 255);

			glm::vec3 colro1(base * 0, base * 230, base * 0);
			glm::vec3 colro2(base * 214, base * 214, base * 214);


			glm::vec3 finalColor = glm::lerp(colro1, colro2, height + 0.9f);

			vertex[vertexIndex + 0] = x;
			vertex[vertexIndex + 1] = height * 50;
			vertex[vertexIndex + 2] = y;

			vertex[vertexIndex + 3] = finalColor.x;
			vertex[vertexIndex + 4] = finalColor.y;
			vertex[vertexIndex + 5] = finalColor.z;



			if (x < 100 - 1 && y < 100 - 1)
			{

				index[InxIndex + 0] = indexI + 1;
				index[InxIndex + 1] = indexI;
				index[InxIndex + 2] = indexI + width;
				index[InxIndex + 3] = indexI + width;
				index[InxIndex + 4] = indexI + width + 1;
				index[InxIndex + 5] = indexI + 1;
				InxIndex += 6;
			}


			vertexIndex += 6;

			indexI++;
		}
	}

	glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), glm::vec3(10, 0.5, 10));

	World::addEngineSystem(new Camera3DSystem());
}

void RenderManager::Debug()
{

}

void RenderManager::Draw()
{

	Shader shader = Resource::getShader("3D_shader");

	

	shader.Use();
	


	model = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), glm::vec3(1, 1, 1));

	shader.SetMatrix4("projection", m_projection);
	shader.SetMatrix4("model", model);

	glDrawElements(GL_TRIANGLES, 99*99*6, GL_UNSIGNED_INT, 0);
}

void RenderManager::Close()
{

}



RenderManager::~RenderManager()
{
}
