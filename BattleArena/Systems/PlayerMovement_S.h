#pragma once

#include <FireLight.h>
#include "../Components/PlayerMovement.h"

class PlayerMovement_S : public System
{
public:
	PlayerMovement_S();

	void Update(uint32_t entity);

	~PlayerMovement_S();

private:

};

