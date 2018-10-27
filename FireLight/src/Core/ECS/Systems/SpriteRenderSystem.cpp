#include "SpriteRenderSystem.h"



SpriteRenderSystem::SpriteRenderSystem()
{
	registerComponent(Transform::ID);
	registerComponent(Sprite::ID);
}

void SpriteRenderSystem::Update(std::vector<BaseComponent*>& components)
{
	Transform* transform = static_cast<Transform*>(components[0]);
	Sprite* sprite = static_cast<Sprite*>(components[1]);

	RenderSystem::addSprite(transform, sprite);
}


SpriteRenderSystem::~SpriteRenderSystem()
{
}
