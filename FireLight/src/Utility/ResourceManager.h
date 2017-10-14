#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H


#include <map>
#include <string>

#include <GL\gl3w.h>

#include "Resources\Shader.h"
#include "Resources\Texture.h"

namespace FL
{
	class ResourceManager
	{
	public:
	
		static std::map<std::string, Shader> m_Shaders;
		static std::map<std::string, Texture> m_Texture;

		static Shader loadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
		static Shader getShader(std::string name);

		static Texture loadTexture(const char *filePath, bool alpha, std::string name);
		static Texture getTexture(std::string name);
	
		static void Clear();
	
	
	
	private:
	
		ResourceManager(){}
	
		static Shader   loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
		static Texture	loadTextureFromFile(const char *filePath, bool alpha);
	};
}

#endif

