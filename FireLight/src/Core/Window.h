
#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <GLFW\glfw3.h>

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
		bool isClosed() const;


		//get Width and height of Window
		static int getWidth(){ return m_width; }
		static int getHeight(){ return m_height; }
		



		//TODO: change resolution and full screen on/off
		//TODO: mouse and keyboard input
		//TODO: joystik input

		static bool isKeyDown(int keyCode);
		static bool isKeyUp(int keyCode);

		static bool isMouseButtonPressed(int keyCode);
		static void getMousePosition(double& x, double& y);

		static void get_mouse_positions(double &x, double &y);


		~Window();

	private:

		const char *m_title;
		static int m_width, m_height;
		 
		static bool m_keys[1024];
		static bool m_mouse_buttons[32];

		static double mx, my;

		static int m_isKeyPress;

		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend static void window_size_callback(GLFWwindow* window, int width, int height);

		GLFWwindow *m_window;

	};


#endif