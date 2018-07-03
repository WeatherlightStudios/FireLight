#include "App.h"
#include <iostream>
#include "../Utility\Resource.h"
#include "SceneManager.h"
#include "../../imgui/imgui_impl_glfw_gl3.h"
#include "../../imgui/imgui.h"
#include "../Utility/Debug.h"
#include "Time.h"


	App::App(const std::string name, int Width, int Height)
	{
		m_title = name;
		m_width = Width; 
		m_height = Height;
		m_window = new Window(m_width, m_height, m_title.c_str());
	}

	void App::start() 
	{
		//Init GLFW/GL3W and start MainLoop
		glfwInit();
		m_window->Init();
		if (gl3wInit())
		{
			std::cout << "OpenGL failde to inizialize" << std::endl;
		}
		glEnable(GL_DEPTH_TEST);
		glfwSwapInterval(0);
		mainLoop();
	}

	void App::mainLoop()
	{

		//init a game
		Init();
		//Time Handling
		Time::start();

		//MainLoop
		while (!m_window->isClosed())
		{
			Time::Calculate();

			//updateting windows stuff
			//ImGui_ImplGlfwGL3_NewFrame();

			//FixedFrame Update game
			while(Time::GetLag() >= MS_PER_UPDATE)
			{
				//Update(dt);
				SceneManager::update_current_scene(Time::GetDeltaTime());
				Time::reset();
			}

			//SceneManager::debug_current_scene();
			//render game
			render();
			//ImGui::Render();
		
			m_window->Update();
			m_window->UpdateInput();

		}
		shutDown();
	}

	void App::render()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		SceneManager::render_current_scene();
	}

	void App::shutDown() 
	{
		delete(m_window);
		glfwTerminate();
		ImGui_ImplGlfwGL3_Shutdown();
	}

	App::~App()
	{

	}