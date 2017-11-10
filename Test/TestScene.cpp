#include "TestScene.h"



TestScene::TestScene()
{
	player = new Renderable;
}

void TestScene::Init()
{

	x = 0;
	y = 0;

	xx = 0;
	yy = 0;

	//gl3wInit();
	//ResourceManager::LoadTexture("sprite.png", true, "sprite");
	glClearColor(0, 0, 0, 1);
	//carica sprite e la salva con nome "sprite"
	ResourceManager::LoadTexture("Sprites/Paladino_Walk_OLD.png", true, "sprite");
	//applica texture a player
	player->set_texture("sprite");
	//numero di righe e colonne
	player->set_texture_row(glm::vec2(ROW, COLUMNS));
	//aggiunge a scena
	addObject(player);
}
void TestScene::Update(double dt)
{
	/*if (Window::isKeyDown(GLFW_KEY_S))
	{
		
	}
	if (Window::isKeyDown(GLFW_KEY_E))
	{
		yy++;
	}*/

	x = GetAxis(GLFW_KEY_D, GLFW_KEY_A, GRAVITY, dt);
	
	

	//player movement
	//if (Window::isKeyDown(GLFW_KEY_W)) {
	//	//aumenta posizione y
	//	//y+= ySpeed * dt;
	//	//aumenta animazione nella quarta colonna
	//	yy = 3;
	//	xx += ANIM_SPEED * dt;
	//}
	//if (Window::isKeyDown(GLFW_KEY_S)) {
	//	//diminuisce posizione y
	//	//y-= ySpeed * dt;
	//	//aumenta animazione nella prima colonna
	//	yy = 0;
	//	xx += ANIM_SPEED * dt;
	//}
	//if (Window::isKeyDown(GLFW_KEY_D)) {
	//	//x+= xSpeed * dt;
	//}
	//if (Window::isKeyDown(GLFW_KEY_A)) {
	//	//x-= xSpeed * dt;
	//}

	//update position
	player->set_local_position(glm::vec3(x, y, 0));
	//animazione
	player->set_texture_offset(glm::vec2(glm::round(xx),glm::round(yy)));
}

///INPUT SYSTEM///
float TestScene::GetAxis(int PosKey, int NegKey, float Gravity, float dt) {
	
	
	if (!Window::isKeyDown(PosKey) && !Window::isKeyDown(NegKey)) {
		//se li premo entrambi o nessuno dei due scende a 0
		if (currentCenterAxis > 0) {
			currentCenterAxis = glm::max(AXIS_CENTER, currentCenterAxis - Gravity);
		}
		else {
			currentCenterAxis = glm::min(AXIS_CENTER, currentCenterAxis + Gravity);
		}
	}
	else if (Window::isKeyDown(PosKey) && Window::isKeyDown(NegKey)) {
		//se li premo entrambi o nessuno dei due scende a 0
		if (currentCenterAxis > 0) {
			currentCenterAxis = glm::max(AXIS_CENTER, currentCenterAxis - Gravity);
		}
		else {
			currentCenterAxis = glm::min(AXIS_CENTER, currentCenterAxis + Gravity);
		}
	}
	else if (Window::isKeyDown(PosKey)) {
		//se premo il tasto positivo aumenta fino a 1
		currentCenterAxis = glm::min(currentCenterAxis + Gravity, AXIS_EDGE);
	}
	else if (Window::isKeyDown(NegKey)) {
		//se premo il tasto negativo diminuisce fino a -1
		currentCenterAxis = glm::max(currentCenterAxis - Gravity, -AXIS_EDGE);
	}

	return currentCenterAxis;
}

void TestScene::Close()
{

}

TestScene::~TestScene()
{
}
