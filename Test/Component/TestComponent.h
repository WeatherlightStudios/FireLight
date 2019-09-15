#ifndef TESTCOMPONENT_H
#define TESTCOMPONENT_H

#include <FireLight.h>

class TestComponent : public Component
{
public:
	TestComponent();

	void Init();
	void Update();

	~TestComponent();
};


#endif 