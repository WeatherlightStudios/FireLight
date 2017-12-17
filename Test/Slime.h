#pragma once
#include <FireLight.h>
#include "DataCenter.h"
//#include "Player.h"

class Slime : public SceneNode
{
public:
	Slime();
	//Slime(Player* pl);
	Slime(DataCenter* cntr);
	void init();
	void update(double dt);
	void Debug();

	void UpdateAnim(int texX, int texY);
	//void UpdateSlimePosToPlayer(glm::vec3 slimeP);
	~Slime();
private:

	Renderable* slime;
	//Player* player;

	DataCenter* dataCenter;

	glm::vec3 playerPos;

	///slime
	const short SLIME_ROW = 2;
	const short SLIME_COLUMNS = 1;
	const short SLIME_ANIM_SPEED = 4;

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

	//slime
	float slimeSpeed = 0.8;
	float slimeChangingSpeed;
	float speedDecrease = 0.75;
	double slimeLaunchTimer = 0.5;
	double timer = 0;
	glm::vec3 slimeToPlayerDir;
	float slimeHitboxRadius = 0.1;
};
