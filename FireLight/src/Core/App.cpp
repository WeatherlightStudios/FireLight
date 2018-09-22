#include "App.h"

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
		//Time Handling


		

	


		Time::start();

		World::InitGameSystems();

		frameRate = 0;

		double oldTime = glfwGetTime();

		//MainLoop
		while (!m_window->isClosed())
		{
			Time::Calculate();

			//updateting windows stuff
			//ImGui_ImplGlfwGL3_NewFrame();
			double currentTime = glfwGetTime();

			//FixedFrame Update game
			while(Time::GetLag() >= MS_PER_UPDATE)
			{
				//Update(dt);
				SceneManager::update_current_scene();
				World::UpdateGameSystems();
				

				Time::reset();
			}

			Render();
			//SceneManager::debug_current_scene();
			//render game
			//ImGui::Render();
		
			frameRate++;

			if ((currentTime - oldTime) >= 1)
			{
				std::cout << "FPS: " << frameRate << std::endl;
				frameRate = 0;
				oldTime = currentTime;
			}

			m_window->Update();

			m_window->UpdateInput();

		}
		ShutDown();
	}

	void App::Render()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		SceneManager::render_current_scene();
		World::RenderGameSystems();
	}

	void App::ShutDown() 
	{
		glfwTerminate();
		ImGui_ImplGlfwGL3_Shutdown();
	}


	void App::set_window_dimension(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void App::set_window_name(std::string name)
	{
		m_title = name;
	}


	App::~App()
	{

	}