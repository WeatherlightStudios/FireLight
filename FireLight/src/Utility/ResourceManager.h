#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H


#include <map>
#include <string>

#include <GL\gl3w.h>

#include "Resources\Shader.h"

class ResourceManager
{
public:

	static std::map<std::string, Shader> m_Shaders;
	//	static std::map<std::string, Material> m_Merials;

	static Shader loadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
	static Shader getShader(std::string name);




	



	/*static Material LoadMaterial();
	static Material getMaterial();*/


	static void Clear();



private:

	ResourceManager(){}



	static Shader   loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

};

#endif

