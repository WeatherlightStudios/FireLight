#pragma once

#include <FireLight.h>

struct Movement : public Component<Movement>
{
	Movement(float vX, float vY) : VeclotyX(vX), VeclotyY(vY)
	{

	}

	Movement() : VeclotyX(0.0f), VeclotyY(0.0f)
	{

	}



	float VeclotyX;
	float VeclotyY;
};