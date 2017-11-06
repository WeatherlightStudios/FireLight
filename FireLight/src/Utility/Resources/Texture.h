
#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl3w.h>


class Texture
{
public:
	
	GLuint ID;
	
	GLuint Width, Height; 
						  
	GLuint Internal_Format;
	GLuint Image_Format;
						
	GLuint Wrap_S; 
	GLuint Wrap_T; 
	GLuint Filter_Min; 
	GLuint Filter_Max; 
					   
	Texture();
	
	void Generate(GLuint width, GLuint height, unsigned char* data);
	void Bind() const;
};

#endif