#include "TestScene.h"
#include <iostream>
#include <string>
#include <glm\gtx\vector_angle.inl>
#include <glm\gtc\constants.hpp>

TestScene::TestScene()
{
	m_player_test = new Player;
	//player = new Renderable;
	slime = new Renderable;
	runner = new Renderable;
}

void TestScene::Init()
{
	//imposta sfondo della finestra
	glClearColor(192.f/255, 192.f/255, 192.f/255, 1);
	//carica sprites e salva con un nome
	ResourceManager::LoadTexture("Sprites/Paladino_Walk_OLD.png", true, "player");
	ResourceManager::LoadTexture("Sprites/Slime.png", true, "slime");
	//applica texture a un Renderable
	//player->set_texture("player");
	slime->set_texture("slime");
	//numero di righe e colonne per ogni sprite
	//player->set_texture_row(glm::vec2(ROW, COLUMNS));
	slime->set_texture_row(glm::vec2(2, 1));//per ora c'� solo 1 riga e 1 colonna
	//aggiunge a scena
	//add_object(player);
	add_object(slime);
	add_object(m_player_test);
	//player->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	slime->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	m_player_test->set_local_scale(glm::vec3(1, 1, 1));
	slime->set_local_position(glm::vec3(0.5, 0.5, 0));

	//slime setup
	slimeChangingSpeed = slimeSpeed;
	//slime anim setup
	slimeXAnim = SLIME_IDLE;
	slimeYAnim = SLIME_ANIM_Y;


	///RUNNER SETUP
	ResourceManager::LoadTexture("Sprites/PixelEnemy_PlaceHolder.png", true, "runner");
	runner->set_texture("runner");
	runner->set_texture_row(glm::vec2(RUNNER_ROW, RUNNER_COLUMNS));
	add_object(runner);
	runner->set_local_scale(runnerScale);



}
void TestScene::Update(double dt)
{

	//m_camera->update();
	

	/*
	///PLAYER///

	//player Pos
	glm::vec3 playerPos = player->get_world_position();

	//slime pos
	glm::vec3 slimePos = slime->get_world_position();
	
	//player movement
	currentCenterAxisX = GetAxis(GLFW_KEY_D, GLFW_KEY_A, GRAVITY, currentCenterAxisX);
	currentCenterAxisY = GetAxis(GLFW_KEY_W, GLFW_KEY_S, GRAVITY, currentCenterAxisY);

	//direction used for movement
	playerMoveDir = glm::vec3(currentCenterAxisX, currentCenterAxisY, 0);
	if (glm::length(playerMoveDir) != 0) {
		playerMoveDir = glm::normalize(playerMoveDir);
		
		//where the player is facing
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

	//player attack
	
	debug_playerDir = playerFacingDir;
	if (Window::isKeyDown(GLFW_KEY_SPACE)) {
		//where damage is applied
		dmgCoords = playerPos + playerFacingDir * damageDistance;
		//distance from 2 points = Pitagora's theorem
		//non serve valore assoluto perché al quadrato è sempre positivo
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

	
	//update position
	player->set_local_position(playerPos);
	//animazione
	player->set_texture_offset(glm::vec2(glm::round(xAnim),glm::round(yAnim)));
	
	*/


	/*
	///SLIME///

	//constantemente diminuisce la velocit� dello slime
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

	
	


	///RUNNER

	//per vedere se è dentro o fuori dal cerchio basta vedere la distanza dal giocatore
	//se questa è minore di radiusFromPlayer allora runner è troppo vicino, sennò troppo lontano
	//per posizionarsi sul cerchio deve fare una retta da player a runner e spostarsi lungo
	//la retta verso o via dal player

	//posizione runner
	glm::vec3 runnerPos = runner->get_local_position();

	glm::vec3 objectiveDir = glm::vec3(0, 0, 0);



	//i due if sono una threshold, quindi il cerchio è diventato un toroide
	//questo imposta l'obbiettivo principale, entrare nel toroide
	if (glm::distance(runnerPos, playerPos) < radiusFromPlayer - radiusThreshold){
		//enemy è dentro cerchio, quindi allontanati
		//quindi vettore = da player a enemy
		//quindi inverti il vettore
		objectiveDir = runnerPos - playerPos;
	}
	else if (glm::distance(runnerPos, playerPos) > radiusFromPlayer + radiusThreshold) {
		//se enemy è fuori cerchio avvicinati
		//quindi objectivDir è vettore da runner a player
		objectiveDir = playerPos - runnerPos;
	}
	//ora bisogna guardare se si è dentro il toroide e in quel caso correre in senso orario
	if( glm::distance(runnerPos, playerPos) > radiusFromPlayer - radiusThreshold &&
		glm::distance(runnerPos, playerPos) < radiusFromPlayer + radiusThreshold) {
		

		glm::vec3 circleCenter = playerPos;

		//vettore da player a runner + normalizzazione
		glm::vec3 playerToRunnerDir = runnerPos - playerPos;
		playerToRunnerDir = glm::normalize(playerToRunnerDir);
		//calcolo angolo fra asse x e giocatore
		//se y runner < y player angolo = 2pi - calcolo
		float currentAngle = 0;
		if(runnerPos.y < playerPos.y)
			currentAngle = glm::two_pi<float>() - glm::angle(glm::vec3(1, 0, 0), playerToRunnerDir);
		else
			currentAngle = glm::angle(glm::vec3(1, 0, 0), playerToRunnerDir);
		//aggiungi un po' di angolo
		float newAngle = currentAngle + angleIncrement;
		//calcola quanto andare avanti nel cerchio grazie all'angolo
		glm::vec3 normalyzedPos = glm::vec3(glm::cos(newAngle), glm::sin(newAngle), 0);
		//aumenta lunghezza vettore del raggio attorno al player
		glm::vec3 offset = radiusFromPlayer * normalyzedPos;
		//somma al vettore posizione cerchio per centrarlo, quel punto è dove deve andare il runner
		glm::vec3 whereToGo = circleCenter + offset;
		//obbiettivo = modulo vettore tra runner e dove andare
		objectiveDir = glm::normalize(whereToGo - runnerPos);

	}


	//normalyzation
	objectiveDir.z = 0;
	if(glm::length(objectiveDir) != 0)
		objectiveDir = glm::normalize(objectiveDir);


	glm::vec3 newRunnerPos = runnerPos + objectiveDir * runnerSpeed * (float)dt;
	runner->set_local_position(newRunnerPos);

	*/	
	

}


void TestScene::Debug()
{
	ImGui::Begin("Player Class");
	m_player_test->Debug();
	ImGui::End();
	/*
	std::string vx = std::to_string(cameraPos.x);
	std::string vy = std::to_string(cameraPos.y);
	std::string vz = std::to_string(cameraPos.z);
	ImGui::Text(("cameraPos: " + vx + " " + vy + " " + vz).c_str());
	*/
	std::string dmgNumb = std::to_string(dmgDist);
	ImGui::Text(("distance from slime to dmgPoint: " + dmgNumb).c_str());

	std::string vx = std::to_string(debug_playerDir.x);
	std::string vy = std::to_string(debug_playerDir.y);
	std::string vz = std::to_string(debug_playerDir.z);
	ImGui::Text(("debug_playerDir: " + vx + " " + vy + " " + vz).c_str());

	

}


void TestScene::CameraUpdate(Camera *camera)
{
	//cameraPos = camera->get_cameraPos();
	if (Window::isKeyDown(GLFW_KEY_UP))
	{
		camera->translate(glm::vec3(0, 1 * 0.06f,0));
	}

	if (Window::isKeyDown(GLFW_KEY_DOWN))
	{
		camera->translate(glm::vec3(0, -1 * 0.06f, 0));
	}

	if (Window::isKeyDown(GLFW_KEY_LEFT))
	{
		camera->translate(glm::vec3(-1 * 0.06f, 0, 0));
	}

	if (Window::isKeyDown(GLFW_KEY_RIGHT))
	{
		camera->translate(glm::vec3(1 * 0.06f, 0, 0));
	}

	//if (Window::isKeyDown(GLFW_KEY_SPACE)) {
	//	camera->set_transform(glm::vec3(0, 0, -3) + player->get_local_position());
	//	//camera->set_transform(player->get_world_position());
	//}
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
