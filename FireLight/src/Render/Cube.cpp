#include "Cube.h"
#include <iostream>

using namespace std;

Cube::Cube()
{
}

void Cube::init()
{
	cout << "init" << endl;

	const int width = 100;
	const int height = 100;

	vertexData m_data[(width + 1) * (height + 1)];
	unsigned int index[width * height * 6];

	int i = 0;
	int vi = 0;
	int ti = 0;

	for (int y = 0; y < height + 1; y++)
	{
		for (int x = 0; x < width + 1; x++)
		{
			m_data[i].position = glm::vec3(x, 0, y);

			//vi++;
			//ti += 6;
			i++;
		}

		//vi++;
	}

	for (int ti = 0, vi = 0, y = 0; y < height; y++, vi++) {
		for (int x = 0; x < width; x++, ti += 6, vi++) {
			index[ti] = vi;
			index[ti + 3] = index[ti + 2] = vi + 1;
			index[ti + 4] = index[ti + 1] = vi + width + 1;
			index[ti + 5] = vi + width + 2;
		}
	}


	/*index[ti] = vi;
	index[ti + 1] = vi + 1;
	index[ti + 2] = vi + height + 1;
	index[ti + 3] = vi + height + 1;
	index[ti + 4] = vi + height + 2;
	index[ti + 5] = vi + 1;*/



	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	m_vbo.Gen(m_data, sizeof(m_data), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	m_vbo.Unbind();
	glBindVertexArray(0);

}


void Cube::Draw(Camera *camera)
{
	model = glm::scale(glm::translate(glm::mat4(1.0f), this->get_world_position()), this->get_world_scale());
	model = glm::rotate(model, this->get_local_rotation(), glm::vec3(0, 0, 1));

	ResourceManager::GetShader("shader").SetMatrix4("model", model, false);
	ResourceManager::GetShader("shader").SetMatrix4("view", camera->get_viewMatrix(), false);
	ResourceManager::GetShader("shader").SetMatrix4("projection", camera->get_projectionMatrix(), false);
	//  ResourceManager::GetShader("shader").SetVector2f("offset", glm::vec2(0,0), false); 
	//cout << "Draw" << endl;
	ResourceManager::GetShader("shader").Use();



	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES,100 * 100 * 6, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

	//cout << "Render CUBE" << endl;



Cube::~Cube()
{
}
