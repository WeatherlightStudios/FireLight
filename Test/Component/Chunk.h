#pragma once

#include <FireLight.h>

#include <vector>


struct vex
{
	glm::vec3 pos;
	glm::vec3 normal;
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


	void Draw();

	~Chunk();

private:

	std::shared_ptr<FL::VertexBuffer> m_VBO;
	std::shared_ptr<FL::VertexArray> m_VAO;


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

};

