#include "App.h"
#include <chrono>

FL::App::App()
{
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
	//FL::Input::Init();
	glfwSwapInterval(0);

	MainLoop();
}

void FL::App::MainLoop()
{

	//init a game
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
			Time::Reset();
			FL::Input::clearKeys();
			FL::Input::clearMouseMuttons();
		}



		if (DEBUG_MODE)
		{
			SceneManager::DebugCurrentScene();
			FL::Log::Draw();
		}


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
	
	SceneManager::DrawCurrentScene();

}

void FL::App::ShutDown()
{
	SceneManager::CloseCurrentScene();
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
