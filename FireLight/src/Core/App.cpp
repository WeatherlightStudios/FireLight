#include "App.h"
#include <chrono>

FL::App::App()
{
	m_render_manager = std::make_unique<RenderManager>();
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
	//m_render_system->Init();
	m_render_manager->Init();
	Init();
	Time::Start();

	frameRate = 0;

	oldTime = glfwGetTime();

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

		//FPS
		//std::cout << "biscotti" << std::endl;

		ImGui::Text("FPS: %d", currentFPS);


		Render();
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


		currentTime = glfwGetTime();

		frameRate++;

		if (currentTime - oldTime > 1.0)
		{
			currentFPS = frameRate;
			frameRate = 0;
			oldTime = currentTime;
		}

		newWindow->Update();
		newWindow->UpdateInput();


	}
	ShutDown();
}

void FL::App::Render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	m_render_manager->Debug();
	m_render_manager->Draw();

	/*m_render_system->Debug();
	m_render_system->SrotSprites();
	m_render_system->CreateBatches();
	m_render_system->Draw();*/

}

void FL::App::ShutDown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	//m_render_system->Close();
	m_render_manager->Close();
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
