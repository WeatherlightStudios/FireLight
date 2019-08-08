#ifndef GAME_HEADER
#define GAME_HEADER

#include <FireLight.h>
#include "Scenes/GameScene.h"
#include <memory>

class Game : public FL::App
{
public:
	Game();

	void Init();

	~Game();

private:

	std::unique_ptr<GameScene> m_scene;

};


#endif
