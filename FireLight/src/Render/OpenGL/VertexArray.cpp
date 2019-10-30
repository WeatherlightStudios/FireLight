#include "VertexArray.h"


namespace FL {


	static GLenum DataTypeToOpenGLType(DataType type)
	{
		switch (type)
		{
			case FL::DataType::Float: return GL_FLOAT;
			case FL::DataType::Vec2:  return GL_FLOAT;
			case FL::DataType::Vec3:  return GL_FLOAT;
			case FL::DataType::Vec4:  return GL_FLOAT;
			case FL::DataType::Mat3:  return GL_FLOAT;
			case FL::DataType::Mat4:  return GL_FLOAT;
			case FL::DataType::Int:	  return GL_INT;
		}
	}

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &bufferID);
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(bufferID);
	}
	void VertexArray::UnBind()
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer>& buffer)
	{
		Bind();
		buffer->Bind();

		uint32_t index = 0;
		for (auto& element : buffer->GetBufferLayout().GetElements())
		{
			glVertexAttribPointer(index, element.GetTypeSyze(), DataTypeToOpenGLType(element.Type), GL_FALSE, buffer->GetBufferLayout().GetStride(), (void*)element.Offset);
			glEnableVertexAttribArray(index);
			index++;
		}
	}

	void VertexArray::AddIndexBuffer(std::shared_ptr<IndexBuffer>& buffer)
	{
		Bind();
		buffer->Bind();
	}

	VertexArray::~VertexArray()
	{
		glDeleteBuffers(1, &bufferID);
	}
}