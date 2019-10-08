#include "TerrainComponent.h"


TerrainComponent::TerrainComponent()
{
	
}

void TerrainComponent::Init()
{

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  1.0f,0.0f,0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  0.0f,1.0f,0.0f,// bottom right
		-0.5f, -0.5f, 0.0f,  0.0f,0.0f,1.0f,// bottom left
		-0.5f,  0.5f, 0.0f,  1.0f,0.0f,0.0f// top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	//for (int y = 0; y < terrainHeight; y++)
	//{
	//	for (int x = 0; x < terrainWidth; x++)
	//	{
	//		vertices[vertexIndex].pos = glm::vec3(x, 0.0f, y);
	//		vertices[vertexIndex].color = glm::vec3(1,0,0);

	//		indices[IndicesIndex] = vertexIndex;
	//		indices[IndicesIndex] = vertexIndex + terrainWidth + 1;
	//		indices[IndicesIndex] = vertexIndex + terrainWidth;

	//		indices[IndicesIndex] = vertexIndex + terrainWidth + 1;
	//		indices[IndicesIndex] = vertexIndex;
	//		indices[IndicesIndex] = vertexIndex + 1;
	//		 



	//		//IndicesIndex += 6;
	//		//vertexIndex++;
	//	}
	//}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
	glDrawElements(GL_TRIANGLES, (terrainWidth - 1) * (terrainHeight - 1) * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


TerrainComponent::~TerrainComponent()
{

}