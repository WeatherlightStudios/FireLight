#include "ResourceManager.h"
#include "../Core/SceneManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{

}
 
std::shared_ptr<Shader> ResourceManager::LoadShader(std::string path, std::string id)
{
	return SceneManager::GetCurrentScene()->GetResourceManager()->LoadInternalShader(path, id);
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
	return nullptr;
}

std::shared_ptr<Shader> ResourceManager::GetShader(std::string id)
{
	return SceneManager::GetCurrentScene()->GetResourceManager()->GetInternalShader(id);
}

std::shared_ptr<Shader> ResourceManager::GetInternalShader(std::string id)
{
	return m_shaders[id];
}

void ResourceManager::Clear()
{
	m_shaders.clear(); //TODO:: im not sure, need to be check if this clear the memory
}

ResourceManager::~ResourceManager()
{
	
}