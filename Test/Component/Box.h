#pragma once

#include <FireLight.h>
#include <memory>


class Box : public Mesh
{
public:
	Box();

	void Init();
	void Update();

	void UpdateMesh();

	void Draw();



	~Box();
private:

	std::shared_ptr<FL::VertexBuffer> m_VBO;
	std::shared_ptr<FL::VertexArray> m_VAO;
	

	GLuint VAO, VBO;



};

