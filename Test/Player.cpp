#include "Player.h"
#include <iostream>


Player::Player()
{
	m_player = new Renderable;
}


void Player::init()
{
	//ResourceManager::LoadTexture("Sprites/Paladino_Walk_OLD.png", true, "m_player");
	this->set_local_scale(glm::vec3(1,1,1));
	m_player->set_texture("player");
	m_player->set_texture_row(glm::vec2(5, 6));
	m_player->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	this->atuch_children(m_player);
}


void Player::update(double dt)
{
	///PLAYER///

	//m_player Pos
	glm::vec3 playerPos = m_player->get_world_position();

	//slime pos
	//glm::vec3 slimePos = slime->get_world_position();

	//m_player movement
	currentCenterAxisX = GetAxis(GLFW_KEY_D, GLFW_KEY_A, GRAVITY, currentCenterAxisX);
	currentCenterAxisY = GetAxis(GLFW_KEY_W, GLFW_KEY_S, GRAVITY, currentCenterAxisY);

	std::cout << "Hello" << std::endl;

	//direction used for movement
	playerMoveDir = glm::vec3(currentCenterAxisX, currentCenterAxisY, 0);
	if (glm::length(playerMoveDir) != 0) {
		playerMoveDir = glm::normalize(playerMoveDir);

		//where the m_player is facing
		//this gets updated only when playerMoveDir != 0
		playerFacingDir = playerMoveDir;
	}



	playerPos = playerPos + playerMoveDir * playerSpd * (float)dt;

	//playerPos.x += currentCenterAxisX * xSpeed * dt;
	//playerPos.y += currentCenterAxisY * ySpeed * dt;

	//animazione sulla stessa riga
	if (currentCenterAxisX == 0 && currentCenterAxisY == 0) {
		xAnim = IDLE_X;
	}
	else {
		xAnim = glm::clamp((float)(xAnim + xAnimSpeed * dt), (float)WALK_START_X, (float)WALK_END_X);
		if (xAnim == WALK_END_X) xAnim = WALK_START_X;
	}

	//cambio di colonna dell'animazione
	if (currentCenterAxisY > 0 && currentCenterAxisX == 0) {
		yAnim = UP_Y;
	}
	else if (currentCenterAxisY < 0 && currentCenterAxisX == 0) {
		yAnim = DOWN_Y;
	}
	else if (currentCenterAxisX > 0) {
		if (currentCenterAxisY > 0) {
			yAnim = UR_Y;
		}
		else {
			yAnim = DR_Y;
		}
	}
	else if (currentCenterAxisX < 0) {
		if (currentCenterAxisY > 0) {
			yAnim = UL_Y;
		}
		else {
			yAnim = DL_Y;
		}
	}

	//m_player attack

	/*
	if (Window::isKeyDown(GLFW_KEY_SPACE)) {
		//where damage is applied
		dmgCoords = playerPos + playerFacingDir * damageDistance;
		//distance from 2 points = Pitagora's theorem
		//non serve valore assoluto perch� al quadrato � sempre positivo
		float xDist = slimePos.x - dmgCoords.x;
		float yDist = slimePos.y - dmgCoords.y;
		float pitTheorem = glm::sqrt(xDist * xDist + yDist * yDist);
		dmgDist = pitTheorem;
		//std::cout << pitTheorem << std::endl;

		//if distance from enemy + hitboxRadius to this point <= damageRadius
		//then enemy takes damage
		if (pitTheorem < damageRadius + slimeHitboxRadius) {
			//colora di rosso
			slimeXAnim = SLIME_DMG;
			//avvia timer
			timer_dmg = damagedTimer;
		}

	}

	//update timer colore slime
	timer_dmg -= dt;
	if (timer_dmg <= 0) {
		slimeXAnim = SLIME_IDLE;
	}
	*/


	//update position
	m_player->set_local_position(playerPos);
	//animazione
	m_player->set_texture_offset(glm::vec2(glm::round(xAnim), glm::round(yAnim)));
}

void Player::Debug() {
	std::string dmgNumb = std::to_string(currentCenterAxisX);
	ImGui::Text(("input X: " + dmgNumb).c_str());
}


///INPUT SYSTEM///
float Player::GetAxis(int PosKey, int NegKey, float Gravity, float x) {


	if (!Window::isKeyDown(PosKey) && !Window::isKeyDown(NegKey)) {
		//se li premo entrambi o nessuno dei due scende a 0
		if (x > 0) {
			x = glm::max(AXIS_CENTER, x - Gravity);
		}
		else {
			x = glm::min(AXIS_CENTER, x + Gravity);
		}
	}
	else if (Window::isKeyDown(PosKey) && Window::isKeyDown(NegKey)) {
		//se li premo entrambi o nessuno dei due scende a 0
		if (x > 0) {
			x = glm::max(AXIS_CENTER, x - Gravity);
		}
		else {
			x = glm::min(AXIS_CENTER, x + Gravity);
		}
	}
	else if (Window::isKeyDown(PosKey)) {
		//se premo il tasto positivo aumenta fino a 1
		x = glm::min(x + Gravity, AXIS_EDGE);
	}
	else if (Window::isKeyDown(NegKey)) {
		//se premo il tasto negativo diminuisce fino a -1
		x = glm::max(x - Gravity, -AXIS_EDGE);
	}

	return x;
}


Player::~Player()
{
}
