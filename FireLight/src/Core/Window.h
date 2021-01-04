#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <GLFW\glfw3.h>
#include <memory>
#include <glm/glm.hpp>
#include "Input.h"
#include "../../imgui/imgui.h"
#include "../../imgui/imgui_impl_glfw.h"
#include "../../imgui/imgui_impl_opengl3.h"
#include <unordered_map>

namespace FL
{
	struct keyState
	{
		int previusState;
		int currentState;
	};


	class Window
	{
	public:
		Window(int width, int height, const char* title);

		//initialzie Window
		void Init();
		//Pull events of Window
		void UpdateInput();
		//update Window
		void Update();
		// controll if Window is Closed
		bool IsClosed() const;

		void InitIMGUI();

		//TODO:: create setting modifier functions 

		//void UpdateSettings();

		//get Width and height of Window
		static int GetWidth(){ return m_width; }
		static int GetHeight(){ return m_height; }

		static glm::vec2 get_mouse_positions();

		static void SetCursorPosition(float x, float y)
		{
			glfwSetCursorPos(m_window, x, y);
		}


		~Window();

	private:

		const char *m_title;
		static int m_width, m_height;
		
		//static std::unordered_map<int, keyState> m_key;

		//static int m_keys[1024];
		//static bool m_mouse_buttons[32];
		
		//static double mx, my;

		static glm::vec2 m_mouse_position;

		//static int m_isKeyPress;
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend static void window_size_callback(GLFWwindow* window, int width, int height);

		static GLFWwindow *m_window;

	};

}

#endif