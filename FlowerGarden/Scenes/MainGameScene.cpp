#include "MainGameScene.h"

#include "../Components/Draggable.h"

void MainGameScene::Init() {
	//auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png", true, "sprite");

	auto dirt = CreateGameOject();
	dirt->AddComponent(std::make_shared<Transform>(glm::vec2(0, 0), glm::vec2(2, 2)));
	dirt->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(11, 1)));

	auto dirt_dry = CreateGameOject();
	dirt_dry->AddComponent(std::make_shared<Transform>(glm::vec2(100, 0), glm::vec2(2, 2)));
	dirt_dry->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(2, 0)));

	auto dirt_wet = CreateGameOject();
	dirt_wet->AddComponent(std::make_shared<Transform>(glm::vec2(-100, 0), glm::vec2(2, 2)));
	dirt_wet->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(14, 5)));

	auto seedling = CreateGameOject();
	seedling->AddComponent(std::make_shared<Transform>(glm::vec2(0, 100), glm::vec2(2, 2)));
	seedling->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(13, 6)));

	auto tree = CreateGameOject();
	tree->AddComponent(std::make_shared<Transform>(glm::vec2(0, -100), glm::vec2(2, 2)));
	tree->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(4, 2)));

	auto skull = CreateGameOject();
	skull->AddComponent(std::make_shared<Transform>(glm::vec2(100, 100), glm::vec2(2, 2)));
	skull->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(0, 15)));

	auto water = CreateGameOject();
	water->AddComponent(std::make_shared<Transform>(glm::vec2(100, -100), glm::vec2(2, 2)));
	water->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(14, 18)));
	water->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Water));

	auto sun = CreateGameOject();
	sun->AddComponent(std::make_shared<Transform>(glm::vec2(-100, 100), glm::vec2(2, 2)));
	sun->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(16, 22)));
	sun->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Sun));

	auto seed = CreateGameOject();
	seed->AddComponent(std::make_shared<Transform>(glm::vec2(-100, -100), glm::vec2(2, 2)));
	seed->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(32, 32), glm::vec2(20, 5)));
	seed->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Seed));
}

void MainGameScene::Update() {
	
}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

