#pragma once

#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include <stb_image.h>

#include "Resources/Texture.h"
#include "Resources/Shader.h"


class ResourceManager
{
public:
	ResourceManager();

	static std::shared_ptr<Shader> LoadShader(std::string path, std::string id);
	static std::shared_ptr<Shader> LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);

	static std::shared_ptr<Texture> LoadTexture(std::string path, std::string id);

	//static void LoadTexture(std::string path, std::string id, bool alpha, );

	static std::shared_ptr<Shader> GetShader(std::string id);
	static std::shared_ptr<Texture> GetTexture(std::string id);
	//static void GetTexture();

	//void LoadTextureInternal();
	static std::shared_ptr<Texture> GetInternalTexture(std::string id);
 	static std::shared_ptr<Shader> GetInternalShader(std::string id);
	//void GetInternalTexture();

	void Clear();

	~ResourceManager();

private:
	static std::shared_ptr<Shader> LoadInternalShader(std::string path, std::string id);
	static std::shared_ptr<Shader> LoadInternalShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);
	
	static std::shared_ptr<Texture> LoadInternalTexture(std::string path, std::string id);

	static std::unordered_map<std::string, std::shared_ptr<Shader>	> m_shaders;
	static std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
	//std::unordered_map<std::string, std::shared_ptr<Texture>> m_shaders;


};

