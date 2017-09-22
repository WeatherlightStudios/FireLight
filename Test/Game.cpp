#include "Game.h"



Game::Game() : FL::App("Hello", 800,600), m_camera(glm::vec3(0,0,-3), glm::vec3(0,1,0), 90,0, projType::ORTHO)
{

}

void Game::Init()
{
	m_paddle1.Init();
	m_paddle1.gen_quad();
	m_paddle1.set_trasform(glm::vec3(1.3f, 0.0f,0.0f));
	m_paddle1.set_scale(glm::vec3( 0.05f, 800.f/600.f / 4, 1.0f));

	m_paddle2.Init();
	m_paddle2.gen_quad();
	m_paddle2.set_trasform(glm::vec3(-1.3f, 0.0f, 0.0f));
	m_paddle2.set_scale(glm::vec3(0.05f, 800.f / 600.f / 4, 1.0f));

	m_ball.Init();
	m_ball.gen_quad();
	m_ball.set_trasform(glm::vec3(0.0f, 0.0f, 0.0f));
	m_ball.set_scale(glm::vec3(0.05f, 0.05f, 1.0f));

	FL::ResourceManager::loadShader("shader.vert", "fragshader.frag", nullptr, "shader");
}

void Game::Update(double deltaT)
{

	m_camera.update();

	//Window::get_mouse_positions(m_mouseX, m_mouseY);


	//double offsetX = m_mouseX - OldmouseX;
	//double offsetY = OldmouseY - m_mouseY;
	//OldmouseX = m_mouseX;
	//OldmouseY = m_mouseY;


	

	if (Window::isKeyDown(GLFW_KEY_W))
	{
		m_paddle1.translate(glm::vec3(0, 2 * deltaT,0));
	}

	if (Window::isKeyDown(GLFW_KEY_S))
	{
		m_paddle1.translate(glm::vec3(0.0, -2 * deltaT, 0));
	}


	if (Window::isKeyDown(GLFW_KEY_UP))
	{
		m_paddle2.translate(glm::vec3(0, 2 * deltaT, 0));
	}

	if (Window::isKeyDown(GLFW_KEY_DOWN))
	{
		m_paddle2.translate(glm::vec3(0.0, -2 * deltaT, 0));
	}




	// border collision first paddlesw
	if (m_paddle1.get_position().y > 1.0 - 800.f / 600.f / 4 * 0.5f)
	{
		m_paddle1.set_trasform(glm::vec3(1.3, 1.0 - 800.f / 600.f / 4 * 0.5f, 0));
	}

	if (m_paddle1.get_position().y < (1.0 - 800.f / 600.f / 4 * 0.5f) * -1)
	{
		m_paddle1.set_trasform(glm::vec3(1.3, (1.0 - 800.f / 600.f / 4 * 0.5f) * -1, 0));
	}

	//border collision second paddle
	if (m_paddle2.get_position().y > 1.0 - 800.f / 600.f / 4 * 0.5f)
	{
		m_paddle2.set_trasform(glm::vec3(-1.3, 1.0 - 800.f / 600.f / 4 * 0.5f, 0));
	}

	if (m_paddle2.get_position().y < (1.0 - 800.f / 600.f / 4 * 0.5f) * -1)
	{
		m_paddle2.set_trasform(glm::vec3(-1.3, (1.0 - 800.f / 600.f / 4 * 0.5f) * -1, 0));
	}

}

void Game::Draw()
{
	m_paddle1.Render(m_camera);
	m_paddle2.Render(m_camera);
	m_ball.Render(m_camera);
}

void Game::Close()
{

}


Game::~Game()
{

}
