#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <glm\glm.hpp>
#include <GL\gl3w.h>

#include "Resource.h"
#include "../../imgui/imgui_impl_glfw_gl3.h"
#include "../../imgui/imgui.h"
#include "../Core/ECS/Components/Camera2D.h"
#include "../Core/ECS/Component.h"
#include "../Core/ECS/World.h"



struct GL_Line;

class Debug
{
public:
	Debug();
	~Debug();
	static void Init();
	static void DrawPoint(glm::vec2 p1, glm::vec3 color);
	static void DrawLine(glm::vec2 p1, glm::vec2 p2, glm::vec3 color);
	static void DrawQuad();
	static void DrawCircle();
	

private:
	 static GLuint VBO, VAO;

};

#endif 
