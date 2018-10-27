#pragma once

#include "../System.h"

#include "../Components/Camera2D.h"
#include "../Components/Transform.h"

#include "../../Window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera2DSystem : public System
{
public:
	Camera2DSystem();

	void Update(BaseComponent** components);

	~Camera2DSystem();
};

