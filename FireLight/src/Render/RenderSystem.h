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

//Resources
#include "../Utility/Resource.h"
//-------------------------------------------

class RenderSystem
{
public:
	RenderSystem();


	void Init();


	void Debug();




	void Render();



	~RenderSystem();

private:

	GLuint VAO, VBO;

	glm::mat4 m_projection;
private:
	//glm::mat4 model;

	const size_t VERTEX_BUFFER_SIZE = sizeof(float) * 12;
	
};

#endif // ! RENDER_SYSTEM_H
