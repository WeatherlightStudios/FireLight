#include "Input.h"

int FL::Input::m_keys[1024];
int FL::Input::m_Presskeys[1024];
int FL::Input::m_MouseButton[32];
int FL::Input::m_PressMouseButton[32];




FL::Input::Input()
{

}

void FL::Input::Init()
{
	clearKeys();
	clearPressKeys();

	clearMouseMuttons();
	clearMousePressMuttons();
}


bool FL::Input::isKeyUp(int keyCode)
{
	bool currentState = false;
	if (m_keys[keyCode] == GLFW_RELEASE)
	{
		currentState = true;
		//m_keys[keyCode] = -1;
	}
	return currentState;
}

bool FL::Input::isKeyDown(int keyCode)
{
	bool currentState = false;
	if (m_keys[keyCode] == GLFW_PRESS)
	{
		currentState = true;
		//m_keys[keyCode] = -1;
	}
	return currentState;
}



bool FL::Input::isKeyPress(int keyCode)
{
	return m_Presskeys[keyCode] == GLFW_REPEAT || m_Presskeys[keyCode] == GLFW_PRESS;
}


bool FL::Input::isMouseButtonDown(int keyCode)
{
	bool currentState = false;
	if (m_MouseButton[keyCode] == GLFW_PRESS)
	{
		currentState = true;
		//m_keys[keyCode] = -1;
	}
	return currentState;
}

bool FL::Input::isMouseButtonUp(int keyCode)
{
	bool currentState = false;
	if (m_MouseButton[keyCode] == GLFW_RELEASE)
	{
		currentState = true;
		//m_keys[keyCode] = -1;
	}
	return currentState;
}

bool FL::Input::isMouseButtonPress(int keyCode)
{
	return m_PressMouseButton[keyCode] == GLFW_REPEAT || m_PressMouseButton[keyCode] == GLFW_PRESS;
}



void FL::Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	m_keys[key] = action;
	m_Presskeys[key] = action;
}

void FL::Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	m_MouseButton[button] = action;
	m_PressMouseButton[button] = action;
}




FL::Input::~Input()
{
	
}