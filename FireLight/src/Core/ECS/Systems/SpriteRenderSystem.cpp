#include "SpriteRenderSystem.h"



SpriteRenderSystem::SpriteRenderSystem()
{
	registerComponent(Transform::ID);
	registerComponent(Sprite::ID);
	registerComponent(MeshRender::ID);

}

void SpriteRenderSystem::Update(std::vector<BaseComponent*>& components)
{
	Transform* transform = static_cast<Transform*>(components[0]);
	Sprite* sprite = static_cast<Sprite*>(components[1]);
	MeshRender* meshRender = static_cast<MeshRender*>(components[2]);

	RenderSystem::addSprite(transform, sprite, meshRender->m_shader, meshRender->m_texture);
}


SpriteRenderSystem::~SpriteRenderSystem()
{
}
