#include "TestScene.h"
#include <iostream>


TestScene::TestScene()
{
	player = new Renderable;
	slime = new Renderable;
}

void TestScene::Init()
{


	//gl3wInit();
	//ResourceManager::LoadTexture("sprite.png", true, "sprite");
	//imposta sfondo della finestra
	glClearColor(192.f/255, 192.f/255, 192.f/255, 1);
	//carica sprites e salva con un nome
	ResourceManager::LoadTexture("Sprites/Paladino_Walk_OLD.png", true, "player");
	ResourceManager::LoadTexture("Sprites/Slime.png", true, "slime");
	//applica texture a un Renderable
	player->set_texture("player");
	slime->set_texture("slime");
	//numero di righe e colonne per ogni sprite
	player->set_texture_row(glm::vec2(ROW, COLUMNS));
	slime->set_texture_row(glm::vec2(1, 1));//per ora c'è solo 1 riga e 1 colonna
	//aggiunge a scena
	addObject(player);
	addObject(slime);

	player->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	slime->set_local_scale(glm::vec3(0.35, 0.35, 0.35));

	//slime->set_local_position(glm::vec3(0.5, 0.5, 0));

	//slime setup
	slimeChangingSpeed = slimeSpeed;
}
void TestScene::Update(double dt)
{
	
	///PLAYER///

	//player movement
	glm::vec3 playerPos = player->get_world_position();
	
	currentCenterAxisX = GetAxis(GLFW_KEY_D, GLFW_KEY_A, GRAVITY, currentCenterAxisX);
	currentCenterAxisY = GetAxis(GLFW_KEY_W, GLFW_KEY_S, GRAVITY, currentCenterAxisY);

	//std::cout << currentCenterAxisX << std::endl;

	playerPos.x += currentCenterAxisX * xSpeed * dt;
	playerPos.y += currentCenterAxisY * ySpeed * dt;

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

	//update position
	player->set_local_position(playerPos);
	//animazione
	player->set_texture_offset(glm::vec2(glm::round(xAnim),glm::round(yAnim)));


	///SLIME///
	//posizione slime
	glm::vec3 slimePos = slime->get_world_position();

	//constantemente diminuisce la velocità dello slime
	slimeChangingSpeed -= speedDecrease * dt;

	//se la velocità dello slime è sotto lo zero fa partire il timer e blocca il valore
	//altrimenti resetta timer
	if (slimeChangingSpeed > 0) {
		timer = slimeLaunchTimer;
	}
	else {
		slimeChangingSpeed = 0;
		timer -= dt;
	}

	std::cout << "slimeChangingSpeed: " << slimeChangingSpeed << " timer: " << timer <<
		"speedDecrease: " << speedDecrease << std::endl;

	//quando timer è sotto a 0 fa uno scatto, quindi resetta la velocità dello slime
	if (timer <= 0) {

		//direzione da slime a giocatore
		playerDir = playerPos - slimePos;

		//glm::project()
		//ignora asse z
		playerDir.z = 0;
		//proiezione sul piano con modulo 1 (se tutti diversi da 0)
		if (glm::length(playerDir) != 0)
			playerDir = glm::normalize(playerDir);


		slimeChangingSpeed = slimeSpeed;
	}

	//aggiornamento posizione slime
	glm::vec3 newSlimePos = slimePos + playerDir * slimeChangingSpeed * (float)dt;
	slime->set_local_position(newSlimePos);


}

///INPUT SYSTEM///
float TestScene::GetAxis(int PosKey, int NegKey, float Gravity, float x) {
	
	
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

void TestScene::Close()
{

}

TestScene::~TestScene()
{
}
