#pragma once

#include <FireLight.h>
#include "TestScene.h"

class Game : public FL::App
{
public:
	Game();

	void Init();
	~Game();
private:
	//Camera m_camera;

	Renderable m_render;

	TestScene m_testScene;

};