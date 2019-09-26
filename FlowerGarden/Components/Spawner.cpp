#include "Spawner.h"
#include "Draggable.h"

Spawner::Spawner(Scene* scene, std::shared_ptr<GameObject> gridManager) {
	Spawner::scene = scene;
	Spawner::gridManager = gridManager;
}

void Spawner::Init() {
	auto spawnPos = glm::vec2(32, -192 * 2);
	auto water = scene->CreateGameOject();
	water->AddComponent(std::make_shared<Transform>(spawnPos, glm::vec2(4, 4)));
	water->AddComponent(std::make_shared<Sprite>(Resource::getTexture("sprite"), glm::vec2(3, 3), glm::vec2(0, 2), 1));
	water->AddComponent(std::make_shared<Draggable>(Draggable::PickUpType::Water, gridManager, water));
}

void Spawner::Update() {

}
