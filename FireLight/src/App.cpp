#include "App.h"
#include <iostream>
#include "Utility\ResourceManager.h"

namespace FL
{
	App::App(const std::string name, int Width, int Height) : m_camera(glm::vec3(0,0,0), glm::vec3(0, 1.f, 0), -90,0)
	{
		m_title = name;
		m_width = Width;
		m_height = Height;
		m_window = new Window(m_width, m_height, m_title.c_str());
	}

	void App::Start() 
	{

		//Init GLFW/GL3W and start MainLoop
		glfwInit();
		m_window->Init();
		if (gl3wInit())
		{
			std::cout << "OpenGL failde to inizialize" << std::endl;
		}
		glEnable(GL_DEPTH_TEST);
		MainLoop();

	}

	void App::MainLoop()
	{

		//init a game
		Init();

		//Time Handling
		double old_time = glfwGetTime();
		double lag = 0.0;

		//MainLoop
		while (!m_window->isClosed())
		{
			//DeltaTime calculation
			double current_time = glfwGetTime();
			double elapsed = current_time - old_time;
			old_time = current_time;
			lag += elapsed;

			//updateting windows stuff
			m_window->UpdateInput();

			//FixedFrame Update game
			while(lag >= FRAME_LIMIT)
			{
				Update(elapsed);
				lag -= FRAME_LIMIT;
			}

			//render game
			Render();
		
			m_window->Update();

		}
		ShutDown();
	}

	void App::Render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		Draw();
	}

	void App::ShutDown() 
	{
		Close();
		delete(m_window);
		glfwTerminate();
	}

	App::~App()
	{

}

}