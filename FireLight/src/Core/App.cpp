#include "App.h"
#include <chrono>

FL::App::App()
{
}

void FL::App::Start()
{
	LoadConfigFile();
	glfwInit();

	m_new_window = std::make_unique<Window>(m_config_data.screen_width, m_config_data.screen_height, m_config_data.screen_title.c_str());
	m_new_window->Init();

	if (gl3wInit())
	{
		std::cout << "OpenGL failde to inizialize" << std::endl;
	}

	m_new_window->InitIMGUI();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);

	glfwSwapInterval(0);
	MainLoop();
}

void FL::App::FixedUpdate()
{
	SceneManager::UpdateCurrentScene();
	Time::Reset();
	FL::Input::ClearKeys();
	FL::Input::ClearMouseMuttons();
}

void FL::App::Update()
{
	//TODO:: need implement Update Function to Scene and in the SceneManager
}

void FL::App::MainLoop()
{
	Init();
	Time::Start();

	while (!m_new_window->IsClosed())
	{
		Time::Calculate();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		while (Time::GetElapsed() > 0.0)
		{
			FixedUpdate();
			Time::Reset();
		}

		if (m_debug_mode)
		{
			SceneManager::DebugCurrentScene();
			FL::Log::Draw();
		}

		//TODO:: Need more complex implemetation for debug and monitoring of performance
		ImGui::Text("FPS: %f", Time::GetFrameRate());

		Render();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		m_new_window->UpdateInput();
		m_new_window->Update();
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

	const auto screen_settings  = toml::find(data, "Screen_Settings");
	m_config_data.screen_title  = toml::find<std::string>(screen_settings, "name");
	m_config_data.screen_width  = toml::find<int>(screen_settings, "width");
	m_config_data.screen_height = toml::find<int>(screen_settings, "heigth");
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
