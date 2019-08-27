#pragma once


#include "../System.h"

#include "../World.h"
#include "../Components/Camera3D.h"
#include "../Components/Transform.h"

#include "../../../Render/RenderManager.h"
#include "../../Window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



SYSTEM(Camera3DSystem)
{
public:
	Camera3DSystem();

	void Update(uint32_t entity);

	~Camera3DSystem();

private:
};

