#include "VertexBuffer.h"



VertexBuffer::VertexBuffer()
{

}

void VertexBuffer::Gen(const void *Data, unsigned int size, GLbitfield type)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, Data, type);
}


void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


VertexBuffer::~VertexBuffer()
{
}
