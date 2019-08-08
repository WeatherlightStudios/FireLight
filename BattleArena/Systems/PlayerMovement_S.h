#pragma once

#include <FireLight.h>
#include "../Components/PlayerMovement.h"

SYSTEM(PlayerMovement_S)
{
public:
	PlayerMovement_S();

	void Update(uint32_t entity);

	~PlayerMovement_S();

private:

};

