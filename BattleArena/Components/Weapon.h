#pragma once

#include <FireLight.h>

COMPONENT(Weapon)
{
	Weapon(Transform* PPos)
	{
		PlayerPos = PPos;
	}

	Transform* PlayerPos;
	float angle = 0;

};