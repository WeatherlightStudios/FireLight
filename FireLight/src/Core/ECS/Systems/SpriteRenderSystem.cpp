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


	//need refactoring
	/*GLSprite sp;
	sp.posX = transform->Position.x;
	sp.posY = transform->Position.y;
	sp.rotatin = transform->Rotation;
	sp.zLayer = 0;
	sp.scaleX = transform->Scale.x;
	sp.scaleY = transform->Scale.y;
	sp.offsetX = sprite->OffsetX;
	sp.offsetY = sprite->OffsetY;
	sp.row = sprite->Rows;
	sp.collum = sprite->Collums;
	sp.texture = meshRender->m_texture;
	sp.shader = meshRender->m_shader;
*/
	//RenderSystem::addSprite(sp);
}


SpriteRenderSystem::~SpriteRenderSystem()
{
}
