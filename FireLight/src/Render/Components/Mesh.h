#pragma once

#include "../../Core/Component.h"
#include "../../Core/MessageSystem/MessageBus.h"
#include "../../Core/MessageSystem/Message.h"

#include "../Material.h"

#include <glm/glm.hpp>

class Mesh : public Component
{
public:
	Mesh();

	virtual void Init() {}
	virtual void Update() {}
	virtual void UpdateMesh(){}
	virtual void Draw() {}

	~Mesh();
private:
};

