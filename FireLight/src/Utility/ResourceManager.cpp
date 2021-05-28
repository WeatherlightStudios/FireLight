#include "ResourceManager.h"
#include "../Core/SceneManager.h"
#include <iostream>

std::unordered_map<std::string, std::shared_ptr<Shader>> ResourceManager::m_shaders;


ResourceManager::ResourceManager()
{

}
 
std::shared_ptr<Shader> ResourceManager::LoadShader(std::string path, std::string id)
{
	return SceneManager::GetCurrentScene()->GetResourceManager()->LoadInternalShader(path, id);
}

std::shared_ptr<Shader> ResourceManager::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name)
{
	return SceneManager::GetCurrentScene()->GetResourceManager()->LoadInternalShader(vShaderFile, fShaderFile, gShaderFile, name);
}

std::shared_ptr<Shader> ResourceManager::LoadInternalShader(std::string path, std::string id)
{
	std::ifstream file;
	std::stringstream materia;;
	std::string shader;

	std::regex rgx(R"(\[([\w]*?)\]\n\{\n([\w\W]*?)\n\})");
	std::smatch matches;

	//TODO:: need Geometry and Compute???
	std::string vertex;
	std::string fragment;


	file.open(path);

	materia << file.rdbuf();

	file.close();

	shader = materia.str();

	while (std::regex_search(shader, matches, rgx))
	{
		for (int i = 0; i < matches.size(); i++)
		{
			if (matches[i] == "Material")
			{
				//TODO: need to load the material and generate one
			}

			if (matches[i] == "Vertex")
			{
				vertex = matches[i + 1];
			}

			if (matches[i] == "Fragment")
			{
				fragment = matches[i + 1];
			}


		}
		shader = matches.suffix();
	}

	std::shared_ptr<Shader> GLShader = std::make_shared<Shader>();
	GLShader->Compile(vertex.c_str(), fragment.c_str(), nullptr);
	m_shaders[id] = std::move(GLShader);
	return m_shaders[id];
}

std::shared_ptr<Shader> ResourceManager::GetShader(std::string id)
{
	return SceneManager::GetCurrentScene()->GetResourceManager()->GetInternalShader(id);
}

std::shared_ptr<Shader> ResourceManager::GetInternalShader(std::string id)
{
	return m_shaders[id];
}

std::shared_ptr<Shader> ResourceManager::LoadInternalShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr, std::string name = "")
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
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();
	const GLchar* gShaderCode = geometryCode.c_str();

	std::shared_ptr<Shader> shader = std::make_shared<Shader>();
	shader->Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
	m_shaders[name] = shader;
	return shader;
}

void ResourceManager::Clear()
{
	m_shaders.clear(); //TODO:: im not sure, need to be check if this clear the memory
}

ResourceManager::~ResourceManager()
{
	
}