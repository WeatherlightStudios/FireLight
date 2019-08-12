#include "SpriteRenderSystem.h"



SpriteRenderSystem::SpriteRenderSystem()
{
	registerComponent(Transform::ID);
	registerComponent(Sprite::ID);
	registerComponent(MeshRender::ID);

}

void SpriteRenderSystem::Update(uint32_t entity)
{

	Transform* transform = World::getComponent<Transform>(entity);
	Sprite* sprite = World::getComponent<Sprite>(entity);
	MeshRender* meshRender = World::getComponent<MeshRender>(entity);

	//RenderSystem::addSprite(transform, sprite, meshRender->m_shader, meshRender->m_texture);
}


SpriteRenderSystem::~SpriteRenderSystem()
{
}
