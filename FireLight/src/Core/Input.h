#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <map>

namespace FL
{

	class Input
	{
	public:
		Input();

		static void Init();

		static bool IsKeyDown(int keyCode);
		static bool IsKeyUp(int keyCode);
		static bool IsKeyPress(int keyCode);

		static bool IsMouseButtonDown(int keyCode);
		static bool IsMouseButtonUp(int keyCode);
		static bool IsMouseButtonPress(int keyCode);

		static void ClearKeys()
		{
			for (int i = 0; i < (sizeof(m_keys) / sizeof(*m_keys)); i++)
			{
				m_keys[i] = -1;
			}
		}

		static void ClearPressKeys()
		{
			for (int i = 0; i < (sizeof(m_press_keys) / sizeof(*m_press_keys)); i++)
			{
				m_press_keys[i] = -1;
			}
		}

		static void ClearMousePressMuttons()
		{
			for (int i = 0; i < (sizeof(m_press_mouse_button) / sizeof(*m_press_mouse_button)); i++)
			{
				m_press_mouse_button[i] = -1;
			}
		}

		static void ClearMouseMuttons()
		{
			for (int i = 0; i < (sizeof(m_mouse_button) / sizeof(*m_mouse_button)); i++)
			{
				m_mouse_button[i] = -1;
			}
		}

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

		~Input();

	private:
		static int m_keys[1024];
		static int m_press_keys[1024];

		static int m_mouse_button[32];
		static int m_press_mouse_button[32];
	};

	namespace KEYCODE
	{
		/* Printable keys */
		const unsigned int KEY_SPACE = GLFW_KEY_SPACE;
		const unsigned int KEY_APOSTROPHE = GLFW_KEY_APOSTROPHE;
		const unsigned int KEY_COMMA = GLFW_KEY_COMMA;
		const unsigned int KEY_MINUS = GLFW_KEY_MINUS;
		const unsigned int KEY_PERIOD = GLFW_KEY_PERIOD;
		const unsigned int KEY_SLASH = GLFW_KEY_SLASH;
		const unsigned int KEY_0 = GLFW_KEY_0;
		const unsigned int KEY_1 = GLFW_KEY_1;
		const unsigned int KEY_2 = GLFW_KEY_2;
		const unsigned int KEY_3 = GLFW_KEY_3;
		const unsigned int KEY_4 = GLFW_KEY_4;
		const unsigned int KEY_5 = GLFW_KEY_5;
		const unsigned int KEY_6 = GLFW_KEY_6;
		const unsigned int KEY_7 = GLFW_KEY_7;
		const unsigned int KEY_8 = GLFW_KEY_8;
		const unsigned int KEY_9 = GLFW_KEY_9;
		const unsigned int KEY_SEMICOLON = GLFW_KEY_SEMICOLON;
		const unsigned int KEY_EQUAL = GLFW_KEY_EQUAL;
		const unsigned int KEY_A = GLFW_KEY_A;
		const unsigned int KEY_B = GLFW_KEY_B;
		const unsigned int KEY_C = GLFW_KEY_C;
		const unsigned int KEY_D = GLFW_KEY_D;
		const unsigned int KEY_E = GLFW_KEY_E;
		const unsigned int KEY_F = GLFW_KEY_F;
		const unsigned int KEY_G = GLFW_KEY_G;
		const unsigned int KEY_H = GLFW_KEY_H;
		const unsigned int KEY_I = GLFW_KEY_I;
		const unsigned int KEY_J = GLFW_KEY_J;
		const unsigned int KEY_K = GLFW_KEY_K;
		const unsigned int KEY_L = GLFW_KEY_L;
		const unsigned int KEY_M = GLFW_KEY_M;
		const unsigned int KEY_N = GLFW_KEY_N;
		const unsigned int KEY_O = GLFW_KEY_O;
		const unsigned int KEY_P = GLFW_KEY_P;
		const unsigned int KEY_Q = GLFW_KEY_Q;
		const unsigned int KEY_R = GLFW_KEY_R;
		const unsigned int KEY_S = GLFW_KEY_S;
		const unsigned int KEY_T = GLFW_KEY_T;
		const unsigned int KEY_U = GLFW_KEY_U;
		const unsigned int KEY_V = GLFW_KEY_V;
		const unsigned int KEY_W = GLFW_KEY_W;
		const unsigned int KEY_X = GLFW_KEY_X;
		const unsigned int KEY_Y = GLFW_KEY_Y;
		const unsigned int KEY_Z = GLFW_KEY_Z;
		const unsigned int KEY_LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET;
		const unsigned int KEY_BACKSLASH = GLFW_KEY_BACKSLASH;
		const unsigned int KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;
		const unsigned int KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT;
		const unsigned int KEY_WORLD_1 = GLFW_KEY_WORLD_1;
		const unsigned int KEY_WORLD_2 = GLFW_KEY_WORLD_2;

		/* Function keys */
		const unsigned int KEY_ESCAPE = GLFW_KEY_ESCAPE;
		const unsigned int KEY_ENTER = GLFW_KEY_ENTER;
		const unsigned int KEY_TAB = GLFW_KEY_TAB;
		const unsigned int KEY_BACKSPACE = GLFW_KEY_BACKSPACE;
		const unsigned int KEY_INSERT = GLFW_KEY_INSERT;
		const unsigned int KEY_DELETE = GLFW_KEY_DELETE;
		const unsigned int KEY_RIGHT = GLFW_KEY_RIGHT;
		const unsigned int KEY_LEFT = GLFW_KEY_LEFT;
		const unsigned int KEY_DOWN = GLFW_KEY_DOWN;
		const unsigned int KEY_UP = GLFW_KEY_UP;
		const unsigned int KEY_PAGE_UP = GLFW_KEY_PAGE_UP;
		const unsigned int KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN;
		const unsigned int KEY_HOME = GLFW_KEY_HOME;
		const unsigned int KEY_END = GLFW_KEY_END;
		const unsigned int KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK;
		const unsigned int KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK;
		const unsigned int KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK;
		const unsigned int KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN;
		const unsigned int KEY_PAUSE = GLFW_KEY_PAUSE;
		const unsigned int KEY_F1 = GLFW_KEY_F1;
		const unsigned int KEY_F2 = GLFW_KEY_F2;
		const unsigned int KEY_F3 = GLFW_KEY_F3;
		const unsigned int KEY_F4 = GLFW_KEY_F4;
		const unsigned int KEY_F5 = GLFW_KEY_F5;
		const unsigned int KEY_F6 = GLFW_KEY_F6;
		const unsigned int KEY_F7 = GLFW_KEY_F7;
		const unsigned int KEY_F8 = GLFW_KEY_F8;
		const unsigned int KEY_F9 = GLFW_KEY_F9;
		const unsigned int KEY_F10 = GLFW_KEY_F10;
		const unsigned int KEY_F11 = GLFW_KEY_F11;
		const unsigned int KEY_F12 = GLFW_KEY_F12;
		const unsigned int KEY_F13 = GLFW_KEY_F13;
		const unsigned int KEY_F14 = GLFW_KEY_F14;
		const unsigned int KEY_F15 = GLFW_KEY_F15;
		const unsigned int KEY_F16 = GLFW_KEY_F16;
		const unsigned int KEY_F17 = GLFW_KEY_F17;
		const unsigned int KEY_F18 = GLFW_KEY_F18;
		const unsigned int KEY_F19 = GLFW_KEY_F19;
		const unsigned int KEY_F20 = GLFW_KEY_F20;
		const unsigned int KEY_F21 = GLFW_KEY_F21;
		const unsigned int KEY_F22 = GLFW_KEY_F22;
		const unsigned int KEY_F23 = GLFW_KEY_F23;
		const unsigned int KEY_F24 = GLFW_KEY_F24;
		const unsigned int KEY_F25 = GLFW_KEY_F25;
		const unsigned int KEY_KP_0 = GLFW_KEY_KP_0;
		const unsigned int KEY_KP_1 = GLFW_KEY_KP_1;
		const unsigned int KEY_KP_2 = GLFW_KEY_KP_2;
		const unsigned int KEY_KP_3 = GLFW_KEY_KP_3;
		const unsigned int KEY_KP_4 = GLFW_KEY_KP_4;
		const unsigned int KEY_KP_5 = GLFW_KEY_KP_5;
		const unsigned int KEY_KP_6 = GLFW_KEY_KP_6;
		const unsigned int KEY_KP_7 = GLFW_KEY_KP_7;
		const unsigned int KEY_KP_8 = GLFW_KEY_KP_8;
		const unsigned int KEY_KP_9 = GLFW_KEY_KP_9;
		const unsigned int KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL;
		const unsigned int KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE;
		const unsigned int KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY;
		const unsigned int KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT;
		const unsigned int KEY_KP_ADD = GLFW_KEY_KP_ADD;
		const unsigned int KEY_KP_ENTER = GLFW_KEY_KP_ENTER;
		const unsigned int KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL;
		const unsigned int KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT;
		const unsigned int KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL;
		const unsigned int KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT;
		const unsigned int KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER;
		const unsigned int KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT;
		const unsigned int KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;
		const unsigned int KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT;
		const unsigned int KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER;
		const unsigned int KEY_MENU = GLFW_KEY_MENU;

		//MOUSE
		const unsigned int MOUSE_BUTTON_1 = GLFW_MOUSE_BUTTON_1;
		const unsigned int MOUSE_BUTTON_2 = GLFW_MOUSE_BUTTON_2;
		const unsigned int MOUSE_BUTTON_3 = GLFW_MOUSE_BUTTON_3;
		const unsigned int MOUSE_BUTTON_4 = GLFW_MOUSE_BUTTON_4;
		const unsigned int MOUSE_BUTTON_5 = GLFW_MOUSE_BUTTON_5;
		const unsigned int MOUSE_BUTTON_6 = GLFW_MOUSE_BUTTON_6;
		const unsigned int MOUSE_BUTTON_7 = GLFW_MOUSE_BUTTON_7;
		const unsigned int MOUSE_BUTTON_8 = GLFW_MOUSE_BUTTON_8;
		const unsigned int MOUSE_BUTTON_LAST = GLFW_MOUSE_BUTTON_LAST;
		const unsigned int MOUSE_BUTTON_LEFT = GLFW_MOUSE_BUTTON_LEFT;
		const unsigned int MOUSE_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_RIGHT;
		const unsigned int MOUSE_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE;

		//jOYSTICK
		const unsigned int KEY_JOYSTICK_1 = GLFW_JOYSTICK_1;
		const unsigned int KEY_JOYSTICK_2 = GLFW_JOYSTICK_2;
		const unsigned int KEY_JOYSTICK_3 = GLFW_JOYSTICK_3;
		const unsigned int KEY_JOYSTICK_4 = GLFW_JOYSTICK_4;
		const unsigned int KEY_JOYSTICK_5 = GLFW_JOYSTICK_5;
		const unsigned int KEY_JOYSTICK_6 = GLFW_JOYSTICK_6;
		const unsigned int KEY_JOYSTICK_7 = GLFW_JOYSTICK_7;
		const unsigned int KEY_JOYSTICK_8 = GLFW_JOYSTICK_8;
		const unsigned int KEY_JOYSTICK_9 = GLFW_JOYSTICK_9;
		const unsigned int KEY_JOYSTICK_10 = GLFW_JOYSTICK_10;
		const unsigned int KEY_JOYSTICK_11 = GLFW_JOYSTICK_11;
		const unsigned int KEY_JOYSTICK_12 = GLFW_JOYSTICK_12;
		const unsigned int KEY_JOYSTICK_13 = GLFW_JOYSTICK_13;
		const unsigned int KEY_JOYSTICK_14 = GLFW_JOYSTICK_14;
		const unsigned int KEY_JOYSTICK_15 = GLFW_JOYSTICK_15;
		const unsigned int KEY_JOYSTICK_16 = GLFW_JOYSTICK_16;
		const unsigned int KEY_JOYSTICK_LAST = GLFW_JOYSTICK_LAST;
	}
}
#endif
