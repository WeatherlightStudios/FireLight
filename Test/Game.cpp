#include "Game.h"



Game::Game() : FL::App("Hello", 800,600), m_camera(glm::vec3(0,0,-3), glm::vec3(0,1,0), 90,0)
{

}

void Game::Init()
{
	m_terrain.Init();
	m_terrain.generateQuad();



	FL::ResourceManager::loadShader("shader.vert", "fragshader.frag", nullptr, "shader");
}

void Game::Update(double deltaT)
{

	m_camera.Update();

	Window::get_mouse_positions(m_mouseX, m_mouseY);


	double offsetX = m_mouseX - OldmouseX;
	double offsetY = OldmouseY - m_mouseY;
	OldmouseX = m_mouseX;
	OldmouseY = m_mouseY;

	m_camera.Rotate(offsetX * 0.1f, offsetY * 0.1f);

	if (Window::isKeyDown(GLFW_KEY_W))
	{
		m_camera.Translate(m_camera.get_VectorForward() * 2.f);
	}

	if (Window::isKeyDown(GLFW_KEY_S))
	{
		m_camera.Translate(m_camera.get_VectorForward() * -2.f);
	}

	if (Window::isKeyDown(GLFW_KEY_D))
	{
		m_terrain.Translate(glm::vec3(1 * deltaT,0,0));
	}


}

void Game::Draw()
{
	m_terrain.Render(m_camera);
}

void Game::Close()
{

}


Game::~Game()
{

}
