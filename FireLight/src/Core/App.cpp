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

		Time::Start();

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
				SceneManager::UpdateCurrentScene();
				World::UpdateGameSystems();
				Time::Reset();
			
			}
			
			
			Render();
		

			m_window->Update();

			m_window->UpdateInput();

		}
		ShutDown();
	}

	void App::Render()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		SceneManager::RenderCurrentScene();
		World::RenderGameSystems();
	}

	void App::ShutDown() 
	{
		glfwTerminate();
		ImGui_ImplGlfwGL3_Shutdown();
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