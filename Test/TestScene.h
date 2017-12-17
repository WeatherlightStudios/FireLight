#pragma once

#include <FireLight.h>
#include "Player.h"
#include "Slime.h"
#include "RunnerEnemy.h"

#include "DataCenter.h"

class TestScene : public Scene
{
public:
	TestScene();
	void Init();
	void Update(double dt);
	void CameraUpdate(Camera *camera);
	void Debughing(Debug* debug);
	void Close();
	~TestScene();
	
	//game objects/class objects
	Player* m_player;
	Slime* m_slime;
	RunnerEnemy* m_runner;

	//DataCenter
	DataCenter* dtCenter;

private:

	//INPUT VARIABLES
	const float GRAVITY = 0.1;
	const float AXIS_CENTER = 0;
	const float AXIS_EDGE = 1;
	float currentCenterAxisX = 0;
	float currentCenterAxisY = 0;
	//INPUT FUNCTION
	float GetAxis(int PosKey, int NegKey, float Gravity, float x);
	//player speed
	float playerSpd = 1;
	//float ySpeed = 1;
	//player direction of moovement
	glm::vec3 playerMoveDir;
	glm::vec3 playerFacingDir;
	

};

