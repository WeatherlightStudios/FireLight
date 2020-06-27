#pragma once

#include <FireLight.h>

#include <vector>


struct vex
{
	glm::vec3 pos;
	glm::vec3 normal;
	float AO;
};

class Chunk : public Mesh
{

public:
	Chunk();

	void Init();
	void Update();

	void UpdateMesh();


	int checkNeighbor(int x, int y, int z);

	void AddVertexFace(glm::vec3 pos, glm::vec3 dir);

	int vertexAO(int side1, int side2, int corner) {
		if (side1 && side2) {
			return 3;
		}
		return  (side1 + side2 + corner);
	}


	void Draw();

	~Chunk();

private:

	std::shared_ptr<FL::VertexBuffer> m_VBO;
	std::shared_ptr<FL::VertexArray> m_VAO;

	uint8_t* chunk;

	int ArraySize;

	std::vector<vex> vertexChunk;

	glm::vec3 directions[6]
	{
		glm::vec3(1,0,0), // Destra
		glm::vec3(-1,0,0), // sistra
		glm::vec3(0,1,0), // sopra
		glm::vec3(0,-1,0), // sotto
		glm::vec3(0,0,1), // vanati 
		glm::vec3(0,0,-1), // indietro
	};
		
	const float aoStrenght[4]
	{
		0.8f,
		0.533f,
		0.26666f,
		0.0f,
	};

	const int chunkX = 1024;
	const int chunkY = 128;
	const int chunkZ = 1024;
};

