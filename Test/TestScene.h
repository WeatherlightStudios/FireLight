#pragma once

#include <FireLight.h>

class TestScene : public Scene
{
public:
	TestScene();
	void Init();
	void Update(double dt);
	void Close();
	~TestScene();
private:
	Renderable *m_rend;


	float x, y;

	float xx, yy;
};

