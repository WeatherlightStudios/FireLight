#pragma once

#include <FireLight.h>

#include <glm/gtx/compatibility.hpp>
#include <glm/gtx/rotate_vector.hpp>

struct vertex {
	glm::vec3 pos;
	glm::vec3 normal;
};

class TerrainComponent : public Mesh
{
public:
	TerrainComponent(int positionX, int positionY);

	void Init();
	void Update();


	float GetHeight(float x, float z)
	{
		return 50 - myNoise.GetPerlin((posX * (terrainWidth - 1)) + x, (posY * (terrainHeight - 1)) + z) * 50.0f;
	}


	glm::vec3 CalculateNormal(float x, float z)
	{
		glm::vec3 offset = glm::vec3(1.0f, 1.0f, 0);

		float heightL = GetHeight(x - 1, z);
		float heightR = GetHeight(x + 1, z);
		float heightD = GetHeight(x, z - 1);
		float heightU = GetHeight(x, z + 1);

		glm::vec3 normal = glm::vec3(heightL - heightR, 2.f, heightD - heightU);
		glm::normalize(normal);
		return normal;

	}

	void UpdateMesh();

	void Debug();

	void Draw();


	~TerrainComponent();

private:

	std::shared_ptr<FL::VertexArray> m_VAO;
	std::shared_ptr<FL::VertexBuffer> m_VBO;
	std::shared_ptr<FL::IndexBuffer> m_IBO;


	//GLuint VAO, VBO, IBO;

	vertex* vertices = nullptr;
	GLuint* indices = nullptr;

	const int terrainWidth = 128;
	const int terrainHeight = 128;


	float GrassSlopeThreshold = 0;
	float GrassBlendAmmount = 0;

	int posX;
	int posY;

	FastNoise myNoise;
};
