#include "MainGameScene.h"

#include "../Components/Draggable.h"
#include "../Components/Grid.h"
#include "../Components/Spawner.h"

void MainGameScene::Init() {
	//auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet  = Resource::LoadTexture("Resources/Sprites/FlowerGarden_Tileset.png", true, "sprite");

	auto grid = CreateGameOject();
	grid->AddComponent(std::make_shared<Grid>(this));

	auto spawnPos = glm::vec2(32, -192*2);
	/*
	auto water = CreateGameOject();
	water->AddComponent(std::make_shared<Transform>(spawnPos, glm::vec2(4, 4)));
	water->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(3, 3), glm::vec2(0, 2), 1));
	water->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Water, grid, water));
	*/

	auto spawner = CreateGameOject();
	spawner->AddComponent(std::make_shared<Spawner>());
	
	/*
	auto sun = CreateGameOject();
	sun->AddComponent(std::make_shared<Transform>(glm::vec2(-100, 100), glm::vec2(4, 4)));
	sun->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(3, 3), glm::vec2(1, 2), 10));
	sun->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Sun));

	auto seed = CreateGameOject();
	seed->AddComponent(std::make_shared<Transform>(glm::vec2(-100, -100), glm::vec2(4, 4)));
	seed->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(3, 3), glm::vec2(2, 2), 10));
	seed->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Seed));
	*/
}

void MainGameScene::Update() {
	
}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

