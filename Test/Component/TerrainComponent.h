#pragma once

#include <FireLight.h>

#include <glm/gtx/compatibility.hpp>
#include <glm/gtx/rotate_vector.hpp>

struct vertex {
	glm::vec3 pos;
	glm::vec3 color;
};

class TerrainComponent : public Mesh
{
public:
	TerrainComponent();

	void Init();
	void Update();

	void UpdateMesh();

	void Draw();


	~TerrainComponent();

private:

	GLuint VAO, VBO, IBO;

	vertex* vertices = nullptr;
	GLuint* indices = nullptr;

	const int terrainWidth = 100;
	const int terrainHeight = 100;
	float* terrain = nullptr;

	FastNoise myNoise;
};
