#ifndef VERTEXBUFFER_HEADER
#define VERTEXBUFFER_HEADER

#include <GL\gl3w.h>
#include <glm\glm.hpp>


struct vertexData 
{
	glm::vec3 position;
	glm::vec3 Normal;
};


class VertexBuffer
{
public:
	VertexBuffer();

	void Gen(const void *Data, unsigned int size, GLbitfield type);

	void Bind() const;
	void Unbind() const;

	~VertexBuffer();
private:
	GLuint VBO;
};


#endif
