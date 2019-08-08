#pragma once

#include "../System.h"

#include "../Components/Camera2D.h"
#include "../Components/Transform.h"

#include "../../Window.h"
#include "../World.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera2DSystem : public System
{
public:
	Camera2DSystem();

	void Update(uint32_t entity);

	~Camera2DSystem();
};

