#include "Texture.h"



Texture::Texture()
	: m_width(0), m_height(0), m_internal_format(GL_RGB), m_image_format(GL_RGB), m_wrap_s(GL_REPEAT), m_wrap_t(GL_REPEAT), m_filter_min(GL_LINEAR), m_filter_max(GL_LINEAR)
{

}

void Texture::generate(unsigned char *data, GLuint width, GLuint height)
{
	this->m_width = width;
	this->m_height = height;

	glBindTexture(GL_TEXTURE_2D, this->m_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, this->m_internal_format, width, height, 0, this->m_image_format, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->m_wrap_s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->m_wrap_t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->m_filter_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->m_filter_max);

	glBindTexture(GL_TEXTURE_2D, 0);
}


void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->m_texture);
}


void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{

}
