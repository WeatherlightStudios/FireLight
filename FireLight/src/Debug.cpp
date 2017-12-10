#include "Debug.h"
#include <GL\gl3w.h>
#include "Utility\ResourceManager.h"

struct Gl_line
{
	int m_count;
	void Create()
	{
		glGenVertexArrays(1, &vaoID);
		glGenBuffers(2, vbo);


		glBindVertexArray(vaoID);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_colors), m_colors, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		m_count = 0;

	}

	void Destroy()
	{

	}

	void Vertex(glm::vec2 pos, glm::vec3 color)
	{

		m_vertices[m_count] = pos;
		m_colors[m_count] = color;
		++m_count;
	}

	void Flush(Camera *camera)
	{

		ResourceManager::GetShader("shader").SetMatrix4("view", camera->get_viewMatrix(), false);
		ResourceManager::GetShader("shader").SetMatrix4("projection", camera->get_projectionMatrix(), false);

		ResourceManager::GetShader("debug_line").Use();

		glBindVertexArray(vaoID);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, m_count * sizeof(m_vertices), m_vertices);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, m_count * sizeof(m_colors), m_colors);


		glDrawArrays(GL_LINE, 0, m_count);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		m_count = 0;
	}
	enum { e_maxVertices = 2 * 512};
	glm::vec2 m_vertices[e_maxVertices];
	glm::vec3 m_colors[e_maxVertices];


	GLuint vaoID;
	GLuint vbo[2];

};

void Debug::create() {
	m_lines = new Gl_line;
	m_lines->Create();
}

Debug::Debug()
{

}

void Debug::DrawLine(glm::vec2 p1, glm::vec2 p2, glm::vec3 color)
{
	m_lines->Vertex(p1, color);
	m_lines->Vertex(p2, color);
}

void Debug::flush()
{
	m_lines->Flush(m_camera);
}

Debug::~Debug()
{

}
