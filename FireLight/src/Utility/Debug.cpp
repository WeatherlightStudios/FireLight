#include "Debug.h"


GLuint Debug::VBO;
GLuint Debug::VAO;

void Debug::Init()
{
	auto Debug_Line_S = Resource::LoadShader("source/Shaders/Debug_Line.vert", "source/Shaders/Debug_Line.frag", NULL, "Debug_Line");
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData();

}
void Debug::DrawPoint(glm::vec2 p1, glm::vec3 color)
{

}
void Debug::DrawLine(glm::vec2 p1, glm::vec2 p2, glm::vec3 color)
{

}