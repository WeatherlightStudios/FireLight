#pragma once

#include <FireLight.h>

class Spawner : public Component {
public:
	Spawner() = default;
	Spawner(Scene* scene, std::shared_ptr<GameObject> gridManager);

	void Init();
	void Update();
private:
	Scene* scene;
	std::shared_ptr<GameObject> gridManager;
};