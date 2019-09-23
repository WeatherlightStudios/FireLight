#include "MainGameScene.h"


void MainGameScene::Init() {
	//auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png",    true, "sprite");

	auto player = CreateGameOject().lock();
	player->AddComponent(std::make_shared<Transform>(glm::vec2(0, 0), glm::vec2(1, 1), 0.0f));
	player->AddComponent(std::make_shared<Sprite>());
	player->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	player->GetComponent<Sprite>()->m_row = glm::vec2(1, 1);
	player->GetComponent<Sprite>()->m_offset = glm::vec2(0, 0);
}

void MainGameScene::Update() {
	
}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

