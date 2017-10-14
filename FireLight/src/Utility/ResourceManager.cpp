#include "ResourceManager.h"

#include <iostream>
#include <sstream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace FL
{

std::map<std::string, Shader>		ResourceManager::m_Shaders;
std::map<std::string, Texture>		ResourceManager::m_Texture;


Shader ResourceManager::loadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name)
{
	m_Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return m_Shaders[name];
}

Shader ResourceManager::getShader(std::string name)
{
	return m_Shaders[name];
}


Texture ResourceManager::loadTexture(const char *filePath, bool alpha, std::string name)
{
	m_Texture[name] = loadTextureFromFile(filePath, alpha);
	return m_Texture[name];
}

Texture ResourceManager::getTexture(std::string name)
{
	return m_Texture[name];
}

void ResourceManager::Clear()
{

	for (auto iter : m_Shaders)
		glDeleteProgram(iter.second.ID);
}

Texture	ResourceManager::loadTextureFromFile(const char *filePath, bool alpha)
{
	Texture texture;

	if (alpha)
	{
		texture.m_internal_format = GL_RGBA;
		texture.m_image_format = GL_RGBA;
	}

	int width, height;
	unsigned char* data = stbi_load(filePath, &width, &height,0, texture.m_image_format == GL_RGBA ? STBI_rgb_alpha : STBI_rgb);
	return texture;
}


Shader ResourceManager::loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{

		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		if (gShaderFile != nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}
	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	const GLchar *gShaderCode = geometryCode.c_str();


	Shader shader;
	shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
	return shader;
}

}