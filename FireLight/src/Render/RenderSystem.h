#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
//------------------Includes------------------
//GLM stuffs
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//OpenGL
#include <GL/gl3w.h>

//Imgui
#include "../../imgui/imgui.h"
#include "../Utility/Debugging/Log.h"

//Engine Stuff
#include "CameraSystem.h"
#include "../Utility/Resource.h"
#include "../Utility/Resources/Shader.h"
#include "../Utility/Resources/Texture.h"
#include "../Core/System.h"
#include "Components/Mesh.h"
//-------------------------------------------

class RenderSystem : public System
{
public:
	RenderSystem();

	void Init();

	void Debug();

	void HandleMessage(Message msg);

	void Render();


	void UpdateBuffer(Mesh* mesh);

	void AddMesh();

	void RemoveMesh();

	~RenderSystem();

private:

	GLuint VAO, VBO, IBO;

	glm::mat4 m_projection;
private:
	//glm::mat4 model;
	std::vector<Mesh*> meshes;
	
};

#endif // ! RENDER_SYSTEM_H
