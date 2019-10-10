#include "TerrainComponent.h"


TerrainComponent::TerrainComponent()
{
	
}

void TerrainComponent::Init()
{

	//float vertices[] = {
	//	 0.5f,  0.5f, 0.0f,  1.0f,0.0f,0.0f,  // top right
	//	 0.5f, -0.5f, 0.0f,  0.0f,1.0f,0.0f,// bottom right
	//	-0.5f, -0.5f, 0.0f,  0.0f,0.0f,1.0f,// bottom left
	//	-0.5f,  0.5f, 0.0f,  1.0f,0.0f,0.0f// top left 
	//};
	//unsigned int indices[] = {  // note that we start from 0!
	//	0, 1, 3,  // first Triangle
	//	1, 2, 3   // second Triangle
	//};



	myNoise.SetNoiseType(FastNoise::PerlinFractal);


	int vertexIndex = 0;


	float max = 0;
	float min = 0;

	vertices = new vertex[terrainHeight * terrainWidth];
	indices = new GLuint[(terrainHeight - 1) * (terrainWidth - 1) * 6];
	terrain = new float[terrainHeight * terrainWidth];

	for (float y = 0; y < terrainHeight; y += 1)
	{
		for (float x = 0; x < terrainWidth; x += 1)
		{

			terrain[vertexIndex] = myNoise.GetPerlin(x,y);

			vertexIndex++;
		}
	}


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * terrainHeight * terrainWidth, NULL, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * (terrainHeight - 1) * (terrainWidth - 1) * 6, NULL, GL_DYNAMIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void TerrainComponent::Update()
{

}

void TerrainComponent::UpdateMesh()
{
	

	int vertexIndex = 0;
	int IndicesIndex = 0;

	for (float y = 0; y < terrainHeight; y += 1)
	{
		for (float x = 0; x < terrainWidth; x += 1)
		{

			float height = terrain[(int)(x + y * terrainWidth)];



			vertices[vertexIndex].pos = glm::vec3(x, height * 50.0f, y);

			float base = (1.0f / 255);
			glm::vec3 color1(base * 97, base * 205, base * 255);
			glm::vec3 color2(base * 138, base * 86, base * 54);
			glm::vec3 color3(base * 233, base * 242, base * 242);


			glm::vec3 finalColor = glm::lerp(color1, color2, height + 0.9f);

			vertices[vertexIndex].color = finalColor;


			if (x < terrainWidth - 1 && y < terrainHeight - 1)
			{

				indices[IndicesIndex + 0] = vertexIndex + 1;
				indices[IndicesIndex + 1] = vertexIndex;
				indices[IndicesIndex + 2] = vertexIndex + terrainWidth;

				indices[IndicesIndex + 3] = vertexIndex + terrainWidth;
				indices[IndicesIndex + 4] = vertexIndex + terrainWidth + 1;
				indices[IndicesIndex + 5] = vertexIndex + 1;

				IndicesIndex += 6;
			}



			vertexIndex++;
		}
	}

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertex) * terrainHeight * terrainWidth, vertices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint) * (terrainHeight - 1) * (terrainWidth - 1) * 6, indices);
	glBindVertexArray(0);
}

void TerrainComponent::Draw() 
{
	glm::mat4 model;
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0, 0, 0));

	auto shader = Resource::getShader("terrain_shader");

	shader.Use();
	shader.SetMatrix4("projection", CameraSystem::GetCurrentCamera());
	shader.SetMatrix4("model", model);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glDrawElements(GL_TRIANGLES, (terrainWidth - 1) * (terrainHeight - 1) * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}


TerrainComponent::~TerrainComponent()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
}