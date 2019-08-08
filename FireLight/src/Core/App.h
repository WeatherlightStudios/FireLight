#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <GL\gl3w.h>
#include <GLFW\glfw3.h>

#include "SceneManager.h"
#include "Window.h"
#include "Time.h"

#include "../../imgui/imgui.h"
#include "../../imgui/imgui_impl_glfw.h"
#include "../../imgui/imgui_impl_opengl3.h"

#include "ECS/World.h"
#include "../Render/RenderSystem.h"


#include <ft2build.h>

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

		void SetWindowDimension(int width, int height);
		void SetWindowName(std::string name);
	protected:

		//The GameLoop itself
		void MainLoop();

		//This fucnction provides initialization for the user to initialize the Scene of the engine and load Stuff
		//The function needs to be created when the App class is inherited
		virtual void Init() = 0;

		void Render();
		void ShutDown();

	private:

		bool isRunning;
		double oldTime;
		double deltaLag;
		int frameRate;
		double Lag;

		int	Width;
		int	Height;
		std::string Title;
		std::unique_ptr<FL::Window> newWindow;
	};
}

#endif