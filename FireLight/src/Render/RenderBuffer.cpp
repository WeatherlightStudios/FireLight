#include "RenderBuffer.h"



RenderBuffer::RenderBuffer()
{
	size_t RenderBufferSize = ((sizeof(GL_Sprite) * 6) * 150000);

	std::cout << sizeof(GL_Sprite) << std::endl;
	std::cout << (sizeof(GL_Sprite) * 6) << std::endl;
	std::cout << RenderBufferSize << std::endl;

	Buffer = new GL_Sprite();
	Buffer = (GL_Sprite*)malloc(RenderBufferSize);


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferStorage(GL_ARRAY_BUFFER, RenderBufferSize, NULL, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
	Buffer = (GL_Sprite*)glMapBufferRange(GL_ARRAY_BUFFER,
		0, RenderBufferSize, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	index = 0;
}



void RenderBuffer::Begin()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//Buffer = (GL_Sprite*)glMapBufferRange(GL_ARRAY_BUFFER,0,  GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
}

void RenderBuffer::addData()
{
}

void RenderBuffer::UpdateData(GL_Sprite* data)
{
	memcpy(&Buffer[index], data, sizeof(GL_Sprite) * 6);
	index += 6;
}


void RenderBuffer::End()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
}

void RenderBuffer::beginDraw()
{
	glBindVertexArray(VAO);
}

void RenderBuffer::Draw(GLuint begin, GLuint end)
{
	glDrawArrays(GL_TRIANGLES, begin, end);
}

void RenderBuffer::endDraw()
{
	glBindVertexArray(0);
	//memset(Buffer, 0, sizeof(Buffer));
	index = 0;

}

RenderBuffer::~RenderBuffer()
{

}