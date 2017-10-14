#ifndef TEXTURE_HEADER
#define TEXTURE_HEADER

#include <GL\gl3w.h>

class Texture
{
public:
	GLuint m_texture;

	GLuint m_width;
	GLuint m_height;

	GLuint m_internal_format;
	GLuint m_image_format;

	GLuint m_wrap_s;
	GLuint m_wrap_t;

	GLuint m_filter_min;
	GLuint m_filter_max;

	Texture();
	void generate(unsigned char *data, GLuint width, GLuint height);
	void bind() const;
	void unbind() const;
	~Texture();
private:


};

#endif

