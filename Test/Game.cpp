#include "Game.h"



Game::Game() : FL::App("Hello", 800,600), m_camera(glm::vec3(0,0,-3), glm::vec3(0,1,0), 90,0, projType::ORTHO)
{

}

void Game::Init()
{
	m_paddle1.Init();
	m_paddle1.set_trasform(glm::vec3(1.2f, 0.0f,0.0f));
	m_paddle1.set_color(glm::vec3(0.0,1.0,0.0));
	m_paddle1.set_scale(glm::vec3( 0.05f, 800.f/600.f / 4, 1.0f));
	m_paddle1.gen_quad();

	m_paddle2.Init();
	m_paddle2.set_trasform(glm::vec3(-1.2f, 0.0f, 0.0f));
	m_paddle2.set_color(glm::vec3(0.0, 1.0, 0.0));
	m_paddle2.set_scale(glm::vec3(0.05f, 800.f / 600.f / 4, 1.0f));
	m_paddle2.gen_quad();

	m_ball.Init();
	m_ball.set_trasform(glm::vec3(0.0f, 0.0f, 0.0f));
	m_ball.set_color(glm::vec3(1.0, 0.0, 0.0));
	m_ball.set_scale(glm::vec3(0.05f, 0.05f, 1.0f));
	m_ball.gen_quad();

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

	//std::cout << deltaT << std::endl;

	//ball movement
	glm::vec3 direction = glm::vec3(ball_dx * deltaT, ball_dy * deltaT, 0);
	m_ball.translate(direction);

	

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

	////PHYSICS SETUP////

	//half wall position
	float wall_pos_half_y_paddle = 1 - m_paddle1.get_scale().y * 0.5f;

	float wall_pos_half_y_ball = 1 - m_ball.get_scale().y * 0.5f;
	float wall_pos_half_x_ball = 1.3333 - m_ball.get_scale().x * 0.5f;

	//ball pos
	glm::vec3 ballPos = m_ball.get_position();

	
	////BALL PHYSICS////

	////sfera contro muri

	//muro sopra
	if(m_ball.get_position().y > wall_pos_half_y_ball)
	{
		//mette palla nella posizione giusta
		m_ball.set_trasform(glm::vec3(ballPos.x, wall_pos_half_y_ball, ballPos.z));
		//inverte velocità in asse y
		ball_dy *= -1;
	}

	//muro sotto
	if (m_ball.get_position().y < wall_pos_half_y_ball * -1)
	{
		//mette palla nella posizione giusta
		m_ball.set_trasform(glm::vec3(ballPos.x, wall_pos_half_y_ball * -1, ballPos.z));
		//inverte velocità in asse y
		ball_dy *= -1;
	}

	//muro destro
	if (m_ball.get_position().x > wall_pos_half_x_ball)
	{
		//mette palla nella posizione giusta
		m_ball.set_trasform(glm::vec3(wall_pos_half_x_ball, ballPos.y, ballPos.z));
		//inverte velocità in asse y
		ball_dx *= -1;
	}

	//muro sinistro
	if (m_ball.get_position().x < wall_pos_half_x_ball * -1)
	{
		//mette palla nella posizione giusta
		m_ball.set_trasform(glm::vec3(wall_pos_half_x_ball * -1, ballPos.y, ballPos.z));
		//inverte velocità in asse y
		ball_dx *= -1;
	}

	////pallina contro racchette
	glm::vec3 ballMovement = glm::vec3(ball_dx * deltaT, ball_dy * deltaT, 0);

	//scontro solo in x racchetta sinistra
	if (ballPos.x + ballMovement.x > m_paddle1.get_position().x - m_paddle1.get_scale().x && ballPos.x + ballMovement.x < m_paddle1.get_position().x + m_paddle1.get_scale().x)
	{
		//scontro solo in y racchetta sinistra
		if (ballPos.y + ballMovement.y < m_paddle1.get_position().y + m_paddle1.get_scale().y && ballPos.y + ballMovement.y > m_paddle1.get_position().y - m_paddle1.get_scale().y)
		{
			//cambia direzione
			ball_dx *= -1;
		}
	}

	//scontro solo in x racchetta destra
	if (ballPos.x + ballMovement.x > m_paddle2.get_position().x - m_paddle2.get_scale().x && ballPos.x + ballMovement.x < m_paddle2.get_position().x + m_paddle2.get_scale().x)
	{
		//scontro solo in y racchetta destra
		if (ballPos.y + ballMovement.y < m_paddle2.get_position().y + m_paddle2.get_scale().y && ballPos.y + ballMovement.y > m_paddle2.get_position().y - m_paddle2.get_scale().y)
		{
			//cambia direzione
			ball_dx *= -1;
		}
	}


	////racchetta contro muri

	// border collision first paddle
	if (m_paddle1.get_position().y > wall_pos_half_y_paddle)
	{
		m_paddle1.set_trasform(glm::vec3(1.2, wall_pos_half_y_paddle, 0));
	}

	if (m_paddle1.get_position().y < wall_pos_half_y_paddle * -1)
	{
		m_paddle1.set_trasform(glm::vec3(1.2, wall_pos_half_y_paddle * -1, 0));
	}

	//border collision second paddle
	if (m_paddle2.get_position().y > wall_pos_half_y_paddle)
	{
		m_paddle2.set_trasform(glm::vec3(-1.2, wall_pos_half_y_paddle, 0));
	}

	if (m_paddle2.get_position().y < wall_pos_half_y_paddle * -1)
	{
		m_paddle2.set_trasform(glm::vec3(-1.2,  wall_pos_half_y_paddle * -1, 0));
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
