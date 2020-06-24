#pragma once

#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>

#include "Resources/Texture.h"
#include "Resources/Shader.h"


class ResourceManager
{
public:
	ResourceManager();

	static std::shared_ptr<Shader> LoadShader(std::string path, std::string id);
	//static void LoadTexture(std::string path, std::string id, bool alpha, );

	static std::shared_ptr<Shader> GetShader(std::string id);
	//static void GetTexture();

	//void LoadTextureInternal();

	std::shared_ptr<Shader> GetInternalShader(std::string id);
	//void GetInternalTexture();

	void Clear();

	~ResourceManager();

private:
	std::shared_ptr<Shader> LoadInternalShader(std::string path, std::string id);

	std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaders;
	//std::unordered_map<std::string, std::shared_ptr<Texture>> m_shaders;


};

