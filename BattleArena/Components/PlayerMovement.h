#pragma once

#include <FireLight.h>

struct PlayerMovement : public Component<PlayerMovement>
{
	PlayerMovement()
	{

	}


	float Speed = 100.0f;
};