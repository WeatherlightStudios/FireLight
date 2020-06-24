#pragma once

#include <FireLight.h>

class Chunk : public Mesh
{

public:
	Chunk();

	void Init();
	void Update();

	void UpdateMesh();

	void Draw();

	~Chunk();

private:

	std::shared_ptr<FL::VertexBuffer> m_VBO;
	std::shared_ptr<FL::VertexArray> m_VAO;

};

