#pragma once

#include <FireLight.h>
#include "../Components/Weapon.h"

class WeaponSystem : public System
{
public:
	WeaponSystem(EntityHandler* camera, EntityHandler* player);

	void Update(uint32_t entity);

	~WeaponSystem();

private:
	EntityHandler* m_camera;
	EntityHandler* m_player;
};

