#ifndef GAME_HEADER
#define GAME_HEADER

#include <FireLight.h>
#include "Scenes/MainGameScene.h"
#include <memory>

class FlowerGame : public FL::App
{
public:
	FlowerGame();

	void Init();

	~FlowerGame();

private:

	std::unique_ptr<MainGameScene> m_scene;

};


#endif
