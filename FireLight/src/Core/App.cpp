#include "App.h"
#include <chrono>

	App::App()
	{

	}

	void App::Start() 
	{

		//Init GLFW/GL3W and start MainLoop
		m_window = std::make_unique<Window>(m_width, m_height, m_title.c_str());
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

		Time::Start();

		World::InitGameSystems();



		std::chrono::steady_clock::time_point ms_begin;

		

		std::chrono::steady_clock::time_point ms_end;

		//MainLoop
		while (!m_window->isClosed())
		{
			Time::Calculate();
			

			//updateting windows stuff
			//ImGui_ImplGlfwGL3_NewFrame();
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			bool show_demo_window = true;

			//FixedFrame Update game
			while(Time::GetLag() >= MS_PER_UPDATE)
			{
				SceneManager::UpdateCurrentScene();
				Time::Reset();
			
			}
			//ImGui::ShowDemoWindow(&show_demo_window);
			
			Render();
			
				ImGui::Begin("Test");

				if (ImGui::Button("Test ECS"))
				{
					ms_begin = std::chrono::high_resolution_clock::now();
					World::UpdateGameSystems();
					ms_end = std::chrono::high_resolution_clock::now();

				}

				
				auto ms_Update =  std::chrono::duration_cast<std::chrono::milliseconds>(ms_end - ms_begin);

				ImGui::LabelText(to_string(ms_Update.count()).c_str(),"Ecs");

				ImGui::End();





			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			
			m_window->Update();
			m_window->UpdateInput();

		}
		ShutDown();
	}

	void App::Render()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		SceneManager::RenderCurrentScene();
		//World::RenderGameSystems();
	}

	void App::ShutDown() 
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		glfwTerminate();
	}


	void App::setWindowDimension(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void App::setWindowName(std::string name)
	{
		m_title = name;
	}


	App::~App()
	{

	}