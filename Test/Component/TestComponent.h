#ifndef TESTCOMPONENT_H
#define TESTCOMPONENT_H

#include <FireLight.h>

class TestComponent : public Component
{
public:
	void Init();
	void Update();

private:
	float velocity = 10.0f;
};
#endif 