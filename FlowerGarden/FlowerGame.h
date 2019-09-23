#ifndef GAME_HEADER
#define GAME_HEADER

#include <FireLight.h>
#include "Scenes/MainGameScene.h"
#include <memory>

class FlowerGame : public FL::App
{
public:
	FlowerGame() = default;

	void Init();

private:

	std::unique_ptr<MainGameScene> m_scene;

};


#endif
