#pragma once

#include <FireLight.h>

struct Weapon : public Component<Weapon>
{
	Weapon(Transform* PPos)
	{
		PlayerPos = PPos;
	}

	Transform* PlayerPos;
	float angle = 0;

};