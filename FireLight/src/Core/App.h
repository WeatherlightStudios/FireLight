#ifndef APP_H
#define APP_H


//----------------------INCLUDE STUFF----------------
//STD C++
#include <string>
#include <vector>
#include <memory>
#include <iostream>

//OpenGL
#include <GL\gl3w.h>
#include <GLFW\glfw3.h>

//Core Engine
#include "SceneManager.h"
#include "Window.h"
#include "Time.h"

//IMGUI
#include "../../imgui/imgui.h"
#include "../../imgui/imgui_impl_glfw.h"
#include "../../imgui/imgui_impl_opengl3.h"


#include "../Utility/Debugging/Log.h"

#include <ft2build.h>

#include <toml11/toml.hpp>


//TODO:: Need Refactoring

#define BG_COLOR(r,g,b) glClearColor((1.0 / 255.0) * r##.0, (1.0 / 255.0) * g##.0, (1 / 255.0) * b##.0, 1)

//TEST
#define MS_PER_UPDATE 1 / 60.0

namespace FL
{
	//App is the core class of the Engine. It's used to initialize all systems and load the resources of the game.
	class App
	{

	public:
		App();
		virtual ~App();
		//Function that initializes all subsystems of the engine
		void Start();
		//Function That Update the game logic at fixed frame rate
		void FixedUpdate();
		//Fucntion that Update the systems and the logic at free framerate
		void Update();
		//Fuction that Updates the frame rate parameter
		void UpdateFrameRate();
		//This function is used for enalbe the Debug mode of the engine
		void Set_DEBUG_MODE() { m_DEBUG_MODE = true; }
		//This function is used for set The Window Size
		void SetWindowDimension(int width, int height);
		//This function is used to set the Window name
		void SetWindowName(std::string name);
	protected:
		//The GameLoop itself
		void MainLoop();
		//This fucnction provides initialization for the user to initialize the Scene of the engine and load Stuff
		//The function needs to be created when the App class is inherited
		virtual void Init() = 0;
		//This function Update and draw the render system
		void Render();
		//This function free the memory and close the render contex
		void ShutDown();

	private:

		bool m_IsRunning;

		double m_OldTime;
		double m_CurrentTime;

		int m_FrameRate;
		int m_CurrentFPS;

		bool m_DEBUG_MODE = false;

		//Window Width
		int	m_Width;
		//Window Height
		int	m_Height;
		//Window Title
		std::string m_Title;
		//The window it self
		std::unique_ptr<FL::Window> m_NewWindow;
	};
}

#endif