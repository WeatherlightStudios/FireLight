#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <glm\glm.hpp>
#include "../imgui/imgui_impl_glfw_gl3.h"
#include "../imgui/imgui.h"
#include "Camera.h"


struct Gl_line;
struct GL_point;
struct GL_poligon;

struct GL_pos;


class Debug
{
public:
	Debug();
	~Debug();
	void create();
	void setCamera(Camera *camera) { m_camera = camera; };
	void DrawLine(glm::vec2 p1, glm::vec2 p2, glm::vec3 color);
	void flush();



private:
	Gl_line* m_lines;

	Camera *m_camera;
};

#endif 
