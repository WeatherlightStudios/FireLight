#include "App.h"
#include <chrono>

FL::App::App()
{
	m_render_system = std::make_unique<RenderSystem>();
}

void FL::App::Start() 
{
	//Init GLFW/GL3W and start MainLoop
	newWindow = std::make_unique<Window>(Width, Height, Title.c_str());
	glfwInit();
	newWindow->Init();
	if (gl3wInit())
	{
		std::cout << "OpenGL failde to inizialize" << std::endl;
	}
	newWindow->InitIMGUI();
	glEnable(GL_DEPTH_TEST);
	glfwSwapInterval(0);

	MainLoop();
}

void FL::App::MainLoop()
{

	//init a game
	m_render_system->Init();
	Init();
	Time::Start();

	//MainLoop
	while (!newWindow->isClosed())
	{
		Time::Calculate();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//FixedFrame Update only GameLogic
		while(Time::GetLag() >= MS_PER_UPDATE)
		{
			//FL::Input::Reset();
			SceneManager::UpdateCurrentScene();
			World::UpdateGameSystems();
			Time::Reset();
			newWindow->clearKeys();
		}


		World::UpdateEngineSystems();
		SceneManager::DebugCurrentScene();

		ImGui::Render();

		Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			
		newWindow->Update();
		newWindow->UpdateInput();


	}
	ShutDown();
}

void FL::App::Render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	m_render_system->sortSprites();
	m_render_system->GenerateBatch();
	m_render_system->GenerateBuffer();
	m_render_system->Draw();

	//RenderSystem::GenerateBatch();
	//RenderSystem::Draw();
}

void FL::App::ShutDown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}


void FL::App::SetWindowDimension(int width, int height)
{
	Width = width;
	Height = height;
}

void FL::App::SetWindowName(std::string name)
{
	Title = name;
}


FL::App::~App()
{

}
