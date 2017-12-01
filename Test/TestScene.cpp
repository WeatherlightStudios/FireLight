#include "TestScene.h"
#include <iostream>
#include <string>


TestScene::TestScene()
{
	//setup di classi
	m_player = new Player;
	m_slime = new Slime(m_player);	//a slime e runner vengono passati il player perché
	//m_player = new Player(m_slime);
	m_runner = new RunnerEnemy(m_player);//contiene informazioni che servono alle 2 classi
}

void TestScene::Init()
{
	//imposta sfondo della finestra
	glClearColor(192.f/255, 192.f/255, 192.f/255, 1);

	//carica sprites e salva con un nome (per tutto il gioco)
	ResourceManager::LoadTexture("Sprites/Paladino_Walk_OLD.png", true, "player");
	ResourceManager::LoadTexture("Sprites/Slime.png", true, "slime");
	ResourceManager::LoadTexture("Sprites/PixelEnemy_PlaceHolder.png", true, "runner");
	
	//aggiunge a scena le varie classi di oggetti con Renderable
	add_object(m_player);
	add_object(m_slime);
	add_object(m_runner);
	


}
void TestScene::Update(double dt)
{

}


void TestScene::Debug()
{

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
