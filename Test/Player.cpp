#include "Player.h"



Player::Player()
{
	m_player = new Renderable;
}


void Player::init()
{
	//ResourceManager::LoadTexture("Sprites/Paladino_Walk_OLD.png", true, "player");
	this->set_local_scale(glm::vec3(1,1,1));
	m_player->set_texture("player");
	m_player->set_texture_row(glm::vec2(5, 6));
	m_player->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	this->atuch_children(m_player);
}
void Player::update(double dt)
{
	std::cout << "helllo" << std::endl;
}

Player::~Player()
{
}
