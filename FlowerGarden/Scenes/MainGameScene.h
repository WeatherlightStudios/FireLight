#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <FireLight.h>

class MainGameScene : public Scene
{
public:

	MainGameScene() = default;

	void Init();
	void Update();
	void Debug();
	void Close();

};

#endif

