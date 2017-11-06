#pragma once

#include <FireLight.h>

class Planet : public SceneNode
{
public:
	Planet();
	void Init();
	void Update();
	void Close();
	~Planet();

private:
	Renderable *m_planet;
};

