#include "TerrainComponent.h"


TerrainComponent::TerrainComponent(int positionX, int positionY)
{
	posX = positionX;
	posY = positionY;
}

void TerrainComponent::Init()
{

	myNoise.SetNoiseType(FastNoise::PerlinFractal);
	myNoise.SetFrequency(0.002f);
	myNoise.SetFractalOctaves(3);
	myNoise.SetFractalLacunarity(2.0);
	myNoise.SetFractalGain(0.5);

	int vertexIndex = 0;
	int IndicesIndex = 0;




	vertices = new vertex[terrainHeight * terrainWidth];
	indices = new GLuint[(terrainHeight - 1) * (terrainWidth - 1) * 6];

	vertexIndex = 0;
	IndicesIndex = 0;


	for (float y = 0; y < terrainHeight; y += 1)
	{
		for (float x = 0; x < terrainWidth; x += 1)
		{

			float height = myNoise.GetPerlinFractal((posX * (terrainWidth - 1)) + x, (posY * (terrainHeight - 1)) + y) * 250.0f;



			vertices[vertexIndex].pos = glm::vec3(x, height, y);
			vertices[vertexIndex].normal = glm::vec3(0,0,0);


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


	FL::BufferLayout layout = {
		{FL::DataType::Vec3},
		{FL::DataType::Vec3}
	};

	m_VAO = std::make_shared<FL::VertexArray>();
	m_VBO = std::make_shared<FL::VertexBuffer>();
	m_IBO = std::make_shared<FL::IndexBuffer>();

	m_VBO->BuilBuffer(sizeof(vertex) * terrainHeight * terrainWidth, vertices, GL_STATIC_DRAW);
	m_VBO->SetBufferLayout(layout);

	m_IBO->BuildBuffer(sizeof(GLuint) * (terrainHeight - 1) * (terrainWidth - 1) * 6, indices, GL_STATIC_DRAW);

	m_VAO->AddVertexBuffer(m_VBO);
	m_VAO->AddIndexBuffer(m_IBO);
}

void TerrainComponent::Update()
{

}

void TerrainComponent::UpdateMesh()
{
}

void TerrainComponent::Debug()
{
	ImGui::Begin("Terrain Controls");

	ImGui::SliderFloat("GrassSlopeThreshold", &GrassSlopeThreshold, -1.0f, 1.0f);
	ImGui::SliderFloat("GrassBlendAmmount", &GrassBlendAmmount, -1.0f, 1.0f);

	ImGui::End();
}

void TerrainComponent::Draw() 
{
	glm::mat4 model;
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3((posX * (terrainWidth - 1)), 0, (posY * (terrainHeight - 1))));

	auto shader = Resource::getShader("terrain_shader");

	shader.Use();
	shader.SetMatrix4("projection", CameraSystem::GetCurrentCamera());
	shader.SetMatrix4("model", model);
	shader.SetFloat("_GrassSlopeThreshold", GrassSlopeThreshold);
	shader.SetFloat("_GrassBlendAmount", GrassBlendAmmount);

	m_VAO->Bind();
	m_IBO->Bind();
	glDrawElements(GL_TRIANGLES, (terrainWidth - 1) * (terrainHeight - 1) * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


TerrainComponent::~TerrainComponent()
{
	/*glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
	*/
}