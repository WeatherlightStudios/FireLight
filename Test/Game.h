#pragma once

#include <FireLight.h>
#include "TestScene.h"

class Game : public FL::App
{
public:
	Game();

	void Init();
	void Update(double deltaT);
	void Draw();
	void Close();

	~Game();
private:
	Camera m_camera;
	SceneNode* m_root;
	SceneNode* obj1;
	SceneNode* obj2;

	TestScene *m_testScene;

};