#pragma once

#include <GL/gl3w.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <memory>

namespace FL {

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void UnBind();

		void Init();

		void AddVertexBuffer(std::shared_ptr<VertexBuffer>& buffer);
		void AddIndexBuffer(std::shared_ptr<IndexBuffer>& buffer);



	private:
		
		GLuint bufferID;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertex_buffer_objects;


	};
}
