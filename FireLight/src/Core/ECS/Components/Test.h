#pragma once

#include "../Component.h"

struct Test : public Component<Test>
{
	Test()
	{

	}


	float v = 0;
};