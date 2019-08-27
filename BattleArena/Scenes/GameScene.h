#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <FireLight.h>
#include <Box2D/Box2D.h>

#include "../Systems/FPSCamera.h"


SCENE(GameScene)
{


public:

	GameScene();

	void Init();

	void Update();

	void Debug();

	void Close();


	~GameScene();

private:

	//EntityHandler* camera;
	EntityHandler* testEntity;


};

#endif