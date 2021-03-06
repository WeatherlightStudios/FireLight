
#ifndef RESOURCE_H
#define RESOURCE_H

#include <map>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/gl3w.h>

#include "Resources/Texture.h"
#include "Resources/Shader.h"



class Resource
{
public:
	
	static std::map<std::string, Shader>  Shaders;
	static std::map<std::string, Texture> Textures;
	static std::map<std::string, Texture> Fonts;

public:

	static void Init();
	
	static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);

	static Shader   getShader(std::string name);

	static Texture	LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
	
	static Texture	getTexture(std::string name);

	static void     Clear();
private:
	
	Resource() { }
	static Shader  loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

	static Texture loadTextureFromFile(const GLchar *file, GLboolean alpha);

	static Texture loadFontFromFile();


private:
	FT_Library ft;
};

#endif