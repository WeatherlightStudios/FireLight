#pragma once

#include <FireLight.h>

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
	void Draw();


	~TerrainComponent();

private:

	GLuint VAO, VBO, IBO;

	vertex* vertices;
	int* indices;

	const int terrainWidth = 10;
	const int terrainHeight = 10;
};
