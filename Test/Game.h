#ifndef GAME_HEADER
#define GAME_HEADER

#include <FireLight.h>
#include "Scenes\Test_Scene.h"

class Game : public FL::App
{
public:
	void Init();

private:
	std::unique_ptr<Test_Scene> m_scene;
};

#endif
