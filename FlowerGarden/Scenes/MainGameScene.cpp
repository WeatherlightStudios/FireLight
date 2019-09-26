#include "MainGameScene.h"

#include "../Components/Draggable.h"
#include "..//Components/Grid.h"

void MainGameScene::Init() {
	//auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png", true, "sprite");

	

	auto grid = CreateGameOject();
	grid->AddComponent(std::make_shared<Grid>(this));

	/*
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
	*/
}

void MainGameScene::Update() {
	
}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

