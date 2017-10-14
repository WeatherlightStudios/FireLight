#include "Game.h"



Game::Game() : FL::App("Hello", 800,600), m_camera(glm::vec3(0,0,-3), glm::vec3(0,1,0), 90,0, projType::ORTHO)
{

}

void Game::Init()
{
	
}

void Game::Update(double deltaT)
{

	m_camera.update();

	
}

void Game::Draw()
{

}

void Game::Close()
{

}


Game::~Game()
{

}
