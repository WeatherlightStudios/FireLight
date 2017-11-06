
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <GL/gl3w.h>

#include "Resources/Texture.h"
#include "Resources/Shader.h"



class ResourceManager
{
public:
	
	static std::map<std::string, Shader>    Shaders;
	static std::map<std::string, Texture> Textures;
	
	static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);

	static Shader   GetShader(std::string name);

	static Texture LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
	
	static Texture GetTexture(std::string name);

	static void      Clear();
private:
	
	ResourceManager() { }

	static Shader    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

	static Texture loadTextureFromFile(const GLchar *file, GLboolean alpha);
};

#endif