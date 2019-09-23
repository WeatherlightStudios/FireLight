#include "MainGameScene.h"


void MainGameScene::Init() {
	//auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png",    true, "sprite");

	auto dirt = CreateGameOject().lock();
	dirt->AddComponent(std::make_shared<Transform>(glm::vec2(0, 0), glm::vec2(2, 2), 0.0f));
	dirt->AddComponent(std::make_shared<Sprite>());
	dirt->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	dirt->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	dirt->GetComponent<Sprite>()->m_offset = glm::vec2(11, 1);

	auto dirt_dry = CreateGameOject().lock();
	dirt_dry->AddComponent(std::make_shared<Transform>(glm::vec2(100, 0), glm::vec2(2, 2), 0.0f));
	dirt_dry->AddComponent(std::make_shared<Sprite>());
	dirt_dry->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	dirt_dry->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	dirt_dry->GetComponent<Sprite>()->m_offset = glm::vec2(2, 0);

	auto dirt_wet = CreateGameOject().lock();
	dirt_wet->AddComponent(std::make_shared<Transform>(glm::vec2(-100, 0), glm::vec2(2, 2), 0.0f));
	dirt_wet->AddComponent(std::make_shared<Sprite>());
	dirt_wet->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	dirt_wet->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	dirt_wet->GetComponent<Sprite>()->m_offset = glm::vec2(14, 5);

	auto seedling = CreateGameOject().lock();
	seedling->AddComponent(std::make_shared<Transform>(glm::vec2(0, 100), glm::vec2(2, 2), 0.0f));
	seedling->AddComponent(std::make_shared<Sprite>());
	seedling->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	seedling->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	seedling->GetComponent<Sprite>()->m_offset = glm::vec2(13, 6);

	auto tree = CreateGameOject().lock();
	tree->AddComponent(std::make_shared<Transform>(glm::vec2(0, -100), glm::vec2(2, 2), 0.0f));
	tree->AddComponent(std::make_shared<Sprite>());
	tree->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	tree->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	tree->GetComponent<Sprite>()->m_offset = glm::vec2(4, 2);

	auto skull = CreateGameOject().lock();
	skull->AddComponent(std::make_shared<Transform>(glm::vec2(100, 100), glm::vec2(2, 2), 0.0f));
	skull->AddComponent(std::make_shared<Sprite>());
	skull->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	skull->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	skull->GetComponent<Sprite>()->m_offset = glm::vec2(0, 15);

	auto water = CreateGameOject().lock();
	water->AddComponent(std::make_shared<Transform>(glm::vec2(100, -100), glm::vec2(2, 2), 0.0f));
	water->AddComponent(std::make_shared<Sprite>());
	water->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	water->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	water->GetComponent<Sprite>()->m_offset = glm::vec2(14, 18);

	auto sun = CreateGameOject().lock();
	sun->AddComponent(std::make_shared<Transform>(glm::vec2(-100, 100), glm::vec2(2, 2), 0.0f));
	sun->AddComponent(std::make_shared<Sprite>());
	sun->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	sun->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	sun->GetComponent<Sprite>()->m_offset = glm::vec2(16, 22);

	auto seed = CreateGameOject().lock();
	seed->AddComponent(std::make_shared<Transform>(glm::vec2(-100, -100), glm::vec2(2, 2), 0.0f));
	seed->AddComponent(std::make_shared<Sprite>());
	seed->GetComponent<Sprite>()->m_texture = Resource::getTexture("sprite");
	seed->GetComponent<Sprite>()->m_row = glm::vec2(32, 32);
	seed->GetComponent<Sprite>()->m_offset = glm::vec2(20, 5);
}

void MainGameScene::Update() {
	
}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

