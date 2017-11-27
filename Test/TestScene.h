#pragma once

#include <FireLight.h>

class TestScene : public Scene
{
public:
	TestScene();
	void Init();
	void Update(double dt);
	void CameraUpdate(Camera *camera);
	void Debug();
	void Close();
	~TestScene();
private:
	//game objects
	Renderable *player;
	Renderable *slime;

	//constants for animations
	///player
	const short ROW = 5;
	const short COLUMNS = 6;
	const short ANIM_SPEED = 4;
	///slime
	const short SLIME_ROW = 2;
	const short SLIME_COLUMNS = 1;
	const short SLIME_ANIM_SPEED = 4;

	//ANIMATION VARIABLES
	///player
	//x divisions
	const short IDLE_X = 0;
	const short WALK_START_X = 1;
	const short WALK_END_X = 4;
	//y divisions
	const short DOWN_Y = 0;
	const short DL_Y = 1;
	const short DR_Y = 2;
	const short UP_Y = 3;
	const short UL_Y = 4;
	const short UR_Y = 5;
	//speed variables
	float xAnim, yAnim;
	float xAnimSpeed = 4;
	float yAnimSpeed = 1;
	///slime
	//x division
	const short SLIME_IDLE = 0;
	const short SLIME_DMG = 1;
	//y division
	const short SLIME_ANIM_Y = 0;
	//anim current values
	short slimeXAnim;
	short slimeYAnim;
	//timer values
	float damagedTimer = 1;
	double timer_dmg;

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
	glm::vec3 playerDir;
	
	//player dmg area
	float damageRadius = 0.01;
	float damageDistance = 0.5;
	glm::vec3 dmgCoords;

	//slime
	float slimeSpeed = 0.8;
	float slimeChangingSpeed;
	float speedDecrease = 0.75;
	double slimeLaunchTimer = 0.5;
	double timer = 0;
	glm::vec3 slimeToPlayerDir;
	float slimeHitboxRadius = 0.01;

	//Camera *m_camera;


	///RUNNER
	Renderable *runner;

	const short RUNNER_ROW = 1;
	const short RUNNER_COLUMNS = 1;
	glm::vec3 runnerScale = glm::vec3(0.2, 0.25, 0.25);

	float radiusFromPlayer = 0.65;
	float radiusThreshold = 0.1;
	float angleIncrement = 0.05;

	float runnerSpeed = 1;


};

