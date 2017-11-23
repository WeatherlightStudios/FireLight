#pragma once

#include <FireLight.h>

class TestScene : public Scene
{
public:
	TestScene();
	void Init();
	void Update(double dt);
	//void CameraUpdate(Camera *camera);
	void Close();
	~TestScene();
private:
	//game objects
	Renderable *player;
	Renderable *slime;

	//constants for animations
		//player
	const float ROW = 5;
	const float COLUMNS = 6;
	const float ANIM_SPEED = 4;
		//slime
	//still nothing

	//ANIMATION VARIABLES
		//player
	//x divisions
	const int IDLE_X = 0;
	const int WALK_START_X = 1;
	const int WALK_END_X = 4;
	//y divisions
	const int DOWN_Y = 0;
	const int DL_Y = 1;
	const int DR_Y = 2;
	const int UP_Y = 3;
	const int UL_Y = 4;
	const int UR_Y = 5;
	//speed variables
	float xAnim, yAnim;
	float xAnimSpeed = 4;
	float yAnimSpeed = 1;
		//slime
	//still nothing

	//INPUT VARIABLES
	const float GRAVITY = 0.1;
	const float AXIS_CENTER = 0;
	const float AXIS_EDGE = 1;
	float currentCenterAxisX = 0;
	float currentCenterAxisY = 0;
	//INPUT FUNCTION
	float GetAxis(int PosKey, int NegKey, float Gravity, float x);
	//player speed
	float xSpeed = 1;
	float ySpeed = 1;
	
	//slime
	float slimeSpeed = 0.8;
	float slimeChangingSpeed;
	float speedDecrease = 0.75;
	double slimeLaunchTimer = 0.5;
	double timer = 0;
	glm::vec3 playerDir;


};

