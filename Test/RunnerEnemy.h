#pragma once
#include <FireLight.h>
#include "Player.h"
#include "DataCenter.h"
class RunnerEnemy : public SceneNode
{
public:
	//RunnerEnemy(Player* pl);
	RunnerEnemy(DataCenter* cntr);
	void init();
	void update(double dt);
	void Debug();
	~RunnerEnemy();
private:
	Renderable* runner;
	//Player* player;

	DataCenter* dataCenter;

	glm::vec3 playerPos;

	

	const short RUNNER_ROW = 1;
	const short RUNNER_COLUMNS = 1;
	glm::vec3 runnerScale = glm::vec3(0.2, 0.25, 0.25);

	float radiusFromPlayer = 0.65;
	float radiusThreshold = 0.1;
	float angleIncrement = 0.05;

	float runnerSpeed = 1;



};

