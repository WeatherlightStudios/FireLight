#include "Window.h"
#include <iostream>

int FL::Window::m_width = 0;
int FL::Window::m_height = 0;
glm::vec2 FL::Window::m_mouse_position;
GLFWwindow *FL::Window::m_window;
//int FL::Window::m_keys[1024];

FL::Window::Window(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

void FL::Window::Init()
{
	glfwWindowHint(GLFW_SAMPLES, 16);

	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetKeyCallback(m_window, FL::Input::key_callback);
	glfwSetMouseButtonCallback(m_window, FL::Input::mouse_button_callback);
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	glfwSetWindowSizeCallback(m_window, window_size_callback);
	glfwMakeContextCurrent(m_window);
}


void FL::Window::InitIMGUI()
{
	const char* glsl_version = "#version 150";
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls


	// Setup style
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

void FL::Window::UpdateInput()
{
	glfwPollEvents();
}

void FL::Window::Update()
{
	glfwSwapBuffers(m_window);
}

bool FL::Window::IsClosed() const
{
	return glfwWindowShouldClose(m_window);
}

void FL::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	FL::Window *win = (FL::Window*)glfwGetWindowUserPointer(window);

	win->m_mouse_position = glm::vec2(xpos, ypos);
}

void FL::window_size_callback(GLFWwindow* window, int width, int height)
{
	FL::Window *win = (FL::Window*)glfwGetWindowUserPointer(window);

	win->m_width = width;
	win->m_height = height;

	glViewport(0, 0, width, height);
}

glm::vec2 FL::Window::get_mouse_positions()
{
	return m_mouse_position;
}

FL::Window::~Window()
{
	glfwDestroyWindow(m_window);
}