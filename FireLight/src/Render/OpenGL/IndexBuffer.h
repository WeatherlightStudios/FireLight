#ifndef INDEXBUFFER_HEADER
#define INDEXBUFFER_HEADER

#include <GL\gl3w.h>

class IndexBuffer
{
public:
	IndexBuffer();


	void Gen(const unsigned int *data, unsigned int count);

	void Bind();
	void Unbind();

	inline unsigned int get_count() const { return m_count; }

	~IndexBuffer();



private:

	GLuint IBO;

	unsigned int m_count;

};

#endif