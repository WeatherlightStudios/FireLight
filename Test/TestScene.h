#pragma once

#include <FireLight.h>

class TestScene : public Scene
{
public:
	TestScene();
	void Init();
	void Update(double dt);
	void Close();
	~TestScene();
private:
	Renderable *player;

	const float ROW = 5;
	const float COLUMNS = 6;
	const float ANIM_SPEED = 4;
	
	const float GRAVITY = 0.1;
	const float AXIS_CENTER = 0;
	const float AXIS_EDGE = 1;
	float currentCenterAxis = 0;
	
	float GetAxis(int PosKey, int NegKey, float Gravity, float dt);
	
	float x, y;
	float xSpeed = 1;
	float ySpeed = 1;

	float xx, yy;
};

