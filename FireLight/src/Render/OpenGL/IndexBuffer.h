#pragma once

#include <GL/gl3w.h>


namespace FL
{
	class IndexBuffer
	{
	public:

		IndexBuffer();
		~IndexBuffer();

		void Bind();
		void UnBind();

		void BuildBuffer(GLsizeiptr size, GLbitfield BufferUsage);
		void BuildBuffer(GLsizeiptr size, void* data ,GLbitfield BufferUsage);

	private:
		GLuint m_bufferID;
};
}