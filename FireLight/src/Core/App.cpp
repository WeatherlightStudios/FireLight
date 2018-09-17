#include "App.h"
#include <iostream>
#include "../Utility\Resource.h"
#include "SceneManager.h"
#include "../../imgui/imgui_impl_glfw_gl3.h"
#include "../../imgui/imgui.h"
#include "../Utility/Debug.h"
#include "Time.h"


	App::App()
	{

	}

	void App::Start() 
	{

		//Init GLFW/GL3W and start MainLoop
		m_window = new Window(m_width, m_height, m_title.c_str());
		glfwInit();
		m_window->Init();
		if (gl3wInit())
		{
			std::cout << "OpenGL failde to inizialize" << std::endl;
		}
		glEnable(GL_DEPTH_TEST);
		glfwSwapInterval(0);

		MainLoop();
	}

	void App::MainLoop()
	{

		//init a game
		Init();
		//Time Handling

		Time::start();

		World::InitGameSystems();


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
				World::UpdateGameSystems();
				//m_World->Step(Time::GetDeltaTime(), 10,8);

				

				Time::reset();
			}

			Render();
			//SceneManager::debug_current_scene();
			//render game
			//ImGui::Render();
		
			m_window->Update();

			m_window->UpdateInput();

		}
		ShutDown();
	}

	void App::Render()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		World::RenderGameSystems();
		SceneManager::render_current_scene();
	}

	void App::ShutDown() 
	{
		delete(m_window);
		glfwTerminate();
		ImGui_ImplGlfwGL3_Shutdown();
	}


	void App::set_window_dimension(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void App::set_windiw_name(std::string name)
	{
		m_title = name;
	}


	App::~App()
	{

	}