#include "Input.h"

int FL::Input::m_keys[1024];
int FL::Input::m_press_keys[1024];
int FL::Input::m_mouse_button[32];
int FL::Input::m_press_mouse_button[32];

FL::Input::Input()
{

}

void FL::Input::Init()
{
	ClearKeys();
	ClearPressKeys();

	ClearMouseMuttons();
	ClearMousePressMuttons();
}

bool FL::Input::IsKeyUp(int keyCode)
{
	bool currentState = false;
	if (m_keys[keyCode] == GLFW_RELEASE)
	{
		currentState = true;
	}
	return currentState;
}

bool FL::Input::IsKeyDown(int keyCode)
{
	bool currentState = false;
	if (m_keys[keyCode] == GLFW_PRESS)
	{
		currentState = true;
	}
	return currentState;
}

bool FL::Input::IsKeyPress(int keyCode)
{
	return m_press_keys[keyCode] == GLFW_REPEAT || m_press_keys[keyCode] == GLFW_PRESS;
}

bool FL::Input::IsMouseButtonDown(int keyCode)
{
	bool currentState = false;
	if (m_mouse_button[keyCode] == GLFW_PRESS)
	{
		currentState = true;
	}
	return currentState;
}

bool FL::Input::IsMouseButtonUp(int keyCode)
{
	bool currentState = false;
	if (m_mouse_button[keyCode] == GLFW_RELEASE)
	{
		currentState = true;
	}
	return currentState;
}

bool FL::Input::IsMouseButtonPress(int keyCode)
{
	return m_press_mouse_button[keyCode] == GLFW_REPEAT || m_press_mouse_button[keyCode] == GLFW_PRESS;
}

void FL::Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	m_keys[key] = action;
	m_press_keys[key] = action;
}

void FL::Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	m_mouse_button[button] = action;
	m_press_mouse_button[button] = action;
}

FL::Input::~Input()
{

}