#pragma once

#include <FireLight.h>
#include "../Components/Weapon.h"

SYSTEM(WeaponSystem)
{
public:
	WeaponSystem(EntityHandler* camera, EntityHandler* player);

	void Update(uint32_t entity);

	~WeaponSystem();

private:
	EntityHandler* m_camera;
	EntityHandler* m_player;
};

