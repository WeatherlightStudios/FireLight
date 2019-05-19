#pragma once

#include "../Components/Transform.h"
#include "../Components/Sprite.h"
#include "../Components/MeshRender.h"

#include "../System.h"

#include "../../../Render/RenderSystem.h"


class SpriteRenderSystem : public System
{
public:
	SpriteRenderSystem();

	void Update(uint32_t entity);

	~SpriteRenderSystem();
};

