#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <FireLight.h>
//#include "../Components/PlayerMovement.h"
//#include "../Components/Weapon.h"
//#include "../Systems/PlayerMovement_S.h"
//#include "../Systems/WeaponSystem.h"
//#include <Box2D/Box2D.h>

class MainGameScene : public Scene
{
public:

	MainGameScene();

	void Init();

	void Update();

	void Debug();

	void Close();

	~MainGameScene();

private:
	
};

#endif

