#pragma once

#include <FireLight.h>
#include "../Components/Draggable.h"

//class Draggable_S : public System
SYSTEM(Draggable_S)
{
public:
	Draggable_S(EntityHandler* camera);

	void Update(uint32_t entity);

private:
	~Draggable_S();

	bool IsInside(glm::vec2 inputPos, glm::vec2 areaPos, glm::vec2 areaSize);

	EntityHandler* cam;
};