#ifndef GAME_HEADER
#define GAME_HEADER

#include <FireLight.h>
#include "Scenes\Test_Scene.h"

class Game : public FL::App
{
public:
	Game();

	void Init();

	~Game();

private:

	std::unique_ptr<Test_Scene> m_scene;
};

#endif
