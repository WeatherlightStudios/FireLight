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
	slime->set_texture_row(glm::vec2(2, 1));//per ora c'è solo 1 riga e 1 colonna
	//aggiunge a scena
	addObject(player);
	addObject(slime);

	player->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	slime->set_local_scale(glm::vec3(0.35, 0.35, 0.35));

	//slime->set_local_position(glm::vec3(0.5, 0.5, 0));

	//slime setup
	slimeChangingSpeed = slimeSpeed;
	//slime anim setup
	slimeXAnim = SLIME_IDLE;
	slimeYAnim = SLIME_ANIM_Y;
}
void TestScene::Update(double dt)
{
	
	///PLAYER///

	//player Pos
	glm::vec3 playerPos = player->get_world_position();

	//slime pos
	glm::vec3 slimePos = slime->get_world_position();
	
	//player movement
	currentCenterAxisX = GetAxis(GLFW_KEY_D, GLFW_KEY_A, GRAVITY, currentCenterAxisX);
	currentCenterAxisY = GetAxis(GLFW_KEY_W, GLFW_KEY_S, GRAVITY, currentCenterAxisY);

	playerDir = glm::vec3(currentCenterAxisX, currentCenterAxisY, 0);
	if (glm::length(playerDir) != 0) {
		playerDir = glm::normalize(playerDir);
	}

	playerPos = playerPos + playerDir * playerSpd * (float)dt;

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

	//player attack
	
	if (Window::isKeyDown(GLFW_KEY_SPACE)) {
		//where damage is applied
		dmgCoords = playerDir * damageDistance;
		
		//distance from 2 points = Pitagora's theorem
		//non serve valore assoluto perché al quadrato è sempre positivo
		float xDist = slimePos.x - dmgCoords.x;
		float yDist = slimePos.y - dmgCoords.y;
		float pitTheorem = glm::sqrt(xDist * xDist + yDist * yDist);

		std::cout << pitTheorem << std::endl;

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

	
	//update position
	player->set_local_position(playerPos);
	//animazione
	player->set_texture_offset(glm::vec2(glm::round(xAnim),glm::round(yAnim)));


	///SLIME///

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

	//std::cout << "slimeChangingSpeed: " << slimeChangingSpeed << " timer: " << timer <<
	//	"speedDecrease: " << speedDecrease << std::endl;

	//quando timer è sotto a 0 fa uno scatto, quindi resetta la velocità dello slime
	if (timer <= 0) {

		//direzione da slime a giocatore
		slimeToPlayerDir = playerPos - slimePos;

		//glm::project()
		//ignora asse z
		slimeToPlayerDir.z = 0;
		//proiezione sul piano con modulo 1 (se tutti diversi da 0)
		if (glm::length(slimeToPlayerDir) != 0)
			slimeToPlayerDir = glm::normalize(slimeToPlayerDir);


		slimeChangingSpeed = slimeSpeed;
	}

	//aggiornamento posizione slime
	glm::vec3 newSlimePos = slimePos + slimeToPlayerDir * slimeChangingSpeed * (float)dt;
	slime->set_local_position(newSlimePos);

	//aggiornamento animazione slime
	slime->set_texture_offset(glm::vec2(slimeXAnim, slimeYAnim));


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
