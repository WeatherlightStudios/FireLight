#include "Window.h"
#include <iostream>

int Window::m_width = 0;
int Window::m_height = 0;

bool Window::m_keys[1024];
bool Window::m_mouse_buttons[32];

double Window::mx = 0;
double Window::my = 0;

int Window::m_isKeyPress = 0;


Window::Window(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;

	for (int i = 0; i < 1024; i++)
	{
		m_keys[i] = false;
	}
}

void Window::Init()
{
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetKeyCallback(m_window, key_callback);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	glfwSetWindowSizeCallback(m_window, window_size_callback);
	glfwMakeContextCurrent(m_window);


	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);


	//setUp IMGUI
	//const char* glsl_version = "#version 130";

  // Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls

	//ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	//ImGui_ImplOpenGL3_Init(glsl_version);

	// Setup style
	ImGui::StyleColorsDark();

}

void Window::get_mouse_positions(double &x ,double &y)
{
	x = mx;
	y = my;
}

bool Window::isKeyDown(int keyCode)
{
	return m_keys[keyCode];
}

bool Window::isKeyUp(int keyCode) //<--- TODO:: da rifare completamente
{
	if (m_keys[keyCode] == 1)
	{
		switch (m_isKeyPress)
		{
		case (0) :
			m_isKeyPress = 1;
			return true;
			break;
		case (1) :
			//m_isKeyPress = 0;
			return false;
			break;



		default:
			break;
		}
	}
	else
	{
		m_isKeyPress = 0;
	}
	return false;
}



void Window::UpdateInput()
{
	glfwPollEvents();
}


void Window::Update()
{
	glfwSwapBuffers(m_window);
}

bool Window::isClosed() const
{
	return glfwWindowShouldClose(m_window);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);

	win->m_keys[key] = action != GLFW_RELEASE;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);

	win->m_mouse_buttons[button] = action != GLFW_RELEASE;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);

	win->mx = xpos;
	win->my = ypos;
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);

	glViewport(0, 0, width, height);
}


Window::~Window()
{
	glfwDestroyWindow(m_window);
}