#ifndef GAME_HEADER
#define GAME_HEADER

#include <FireLight.h>
#include "Scenes\Test_Scene.h"

class Game : public App
{
public:
	Game();

	void Init();

	~Game();

private:

	Test_Scene m_scene;
};

#endif
