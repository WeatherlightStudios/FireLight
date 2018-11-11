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
	RenderSystem::Init();
	Init();
	Time::Start();
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

		//FixedFrame Update only GameLogic
		while(Time::GetLag() >= MS_PER_UPDATE)
		{
			SceneManager::UpdateCurrentScene();
			World::UpdateGameSystems();
			Time::Reset();
		}
			
		World::UpdateEngineSystems();
		

		SceneManager::DebugCurrentScene();






		Render();




		ImGui::LabelText("number of objects ", to_string(RenderSystem::getNumberOfObjects()).c_str());
		ImGui::LabelText("number of batch ", to_string(RenderSystem::getNumberOfBatch()).c_str());


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
	RenderSystem::GenerateBatch();
	RenderSystem::Draw();
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