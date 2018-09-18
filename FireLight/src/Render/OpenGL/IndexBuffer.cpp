#include "IndexBuffer.h"



IndexBuffer::IndexBuffer()
{


}

void IndexBuffer::Gen(const unsigned int *data, unsigned int count)
{
	m_count =  count;


	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void IndexBuffer::Bind() 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
}

void IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



IndexBuffer::~IndexBuffer()
{


}
