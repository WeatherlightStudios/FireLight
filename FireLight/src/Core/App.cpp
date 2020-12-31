#include "App.h"
#include <chrono>

FL::App::App()
{
}

void FL::App::Start() 
{
	m_Width = 800;
	m_Height = 600;

	m_Title = "FireLight Enigne v1.0.0a";

	LoadConfigFile();


	m_NewWindow = std::make_unique<Window>(m_configData.screenWidth, m_configData.screenHeigth, m_configData.screenTitle.c_str());



	glfwInit();

	m_NewWindow->Init();

	if (gl3wInit())
	{
		std::cout << "OpenGL failde to inizialize" << std::endl;
	}

	m_NewWindow->InitIMGUI();


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);


	glfwSwapInterval(0);

	MainLoop();
}

void FL::App::FixedUpdate()
{
	SceneManager::UpdateCurrentScene();
	Time::Reset();
	FL::Input::clearKeys();
	FL::Input::clearMouseMuttons();
}

void FL::App::Update()
{
	//TODO:: need implement Update Function to Scene and in the SceneManager
}

void FL::App::UpdateFrameRate()
{
	m_CurrentTime = glfwGetTime();

	m_FrameRate++;

	if (m_CurrentTime - m_OldTime > 1.0)
	{
		m_CurrentFPS = m_FrameRate;
		m_FrameRate = 0;
		m_OldTime = m_CurrentTime;
	}
}

void FL::App::MainLoop()
{
	Init();

	Time::Start();

	m_FrameRate = 0;
	m_OldTime = glfwGetTime();

	while (!m_NewWindow->isClosed())
	{
		Time::Calculate();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		while(Time::GetLag() >= MS_PER_UPDATE)
		{
			FixedUpdate();
		}

		if (m_DEBUG_MODE)
		{
			SceneManager::DebugCurrentScene();
			FL::Log::Draw();
		}

		//TODO:: Need more complex implemetation for debug and monitoring of performance
		//ImGui::Text("FPS: %d", m_CurrentFPS);

		Render();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		UpdateFrameRate();

		m_NewWindow->UpdateInput();
		m_NewWindow->Update();
	}
	ShutDown();
}

void FL::App::Render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	SceneManager::DrawCurrentScene();
}

void FL::App::LoadConfigFile()
{
	const auto data = toml::parse("Resources/config.toml");

	const auto ScreenSettings = toml::find(data, "Screen_Settings");
	m_configData.screenTitle = (std::string)toml::find<std::string>(ScreenSettings, "name");
	m_configData.screenWidth = (int)toml::find<int>(ScreenSettings, "width");
	m_configData.screenHeigth = (int)toml::find<int>(ScreenSettings, "heigth");
}

void FL::App::ShutDown()
{
	SceneManager::CloseCurrentScene();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}

FL::App::~App()
{

}
