#pragma once


#include <FireLight.h>


class RotComp : public Component
{
public:
	RotComp();
	~RotComp();

	void Init();
	void Update();

private:
	float x;
};
