#include "App.h"
#include <iostream>
#include "Utility\ResourceManager.h"

namespace fl
{
	App::App(const std::string name, int Width, int Height) : m_camera(glm::vec3(0,0,0), glm::vec3(0, 1.f, 0), -90,0)
	{
		m_title = name;
		m_width = Width;
		m_height = Height;
		m_window = new Window(m_width, m_height, m_title.c_str());
	}

	void App::Start() 
	{
		glfwInit();
		m_window->Init();
		if (gl3wInit())
		{
			std::cout << "OpenGL failde to inizialize" << std::endl;
		}
		glEnable(GL_DEPTH_TEST);
		MainLoop();

	}

	void App::MainLoop()
	{
		Init();
		double old_time = glfwGetTime();
		double lag = 0.0;


		while (!m_window->isClosed())
		{
			double current_time = glfwGetTime();
			double elapsed = current_time - old_time;
			old_time = current_time;
			lag += elapsed;

			m_window->UpdateInput();

			while(lag >= FRAME_LIMIT)
			{
				Update(elapsed);
				lag -= FRAME_LIMIT;
			}


			Render();
		
			m_window->Update();

		}
		ShutDown();
	}

	void App::Init()
	{

		ResourceManager::loadShader("shader.vert", "fragshader.frag", nullptr, "shader");
		OldmouseX = 400;
		OldmouseY = 300;
		m_rend.Init();

	}

	void App::Update(double deltaT)
	{

		m_camera.Update();
		Window::get_mouse_positions(m_mouseX, m_mouseY);


		float offsetX = m_mouseX - OldmouseX;
		float offsetY = OldmouseY - m_mouseY;
		OldmouseX = m_mouseX;
		OldmouseY = m_mouseY;

		m_camera.Rotate( offsetX * 0.1f, offsetY * 0.1f);

		if (Window::isKeyDown(GLFW_KEY_W))
		{
			m_camera.Translate(m_camera.get_VectorForward() * float(10.0f * deltaT));
		}

		if (Window::isKeyDown(GLFW_KEY_S))
		{
			m_camera.Translate(m_camera.get_VectorForward() * float(-10.0f * deltaT));
		}

		if (Window::isKeyDown(GLFW_KEY_A))
		{
			m_camera.Translate(m_camera.get_VectorRight() * float(-10.0f * deltaT));
		}

		if (Window::isKeyDown(GLFW_KEY_D))
		{
			m_camera.Translate(m_camera.get_VectorRight() * float(10.0f * deltaT));
		}

		if (Window::isKeyDown(GLFW_KEY_LEFT_SHIFT))
		{
			m_camera.Translate(glm::vec3(0.0f, -2.f * deltaT, 0.0f));
		}

		if (Window::isKeyDown(GLFW_KEY_SPACE))
		{
			m_camera.Translate(glm::vec3(0.0f, 2.f * deltaT, 0.0f));
		}


	}

	void App::Render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		m_rend.Render(m_camera);
	}

	void App::ShutDown() 
	{
		delete(m_window);
		glfwTerminate();
	}

	App::~App()
	{

}

}