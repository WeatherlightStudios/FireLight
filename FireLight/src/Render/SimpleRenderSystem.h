#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H
//external icludes
#include <vector>
#include <algorithm>
//internal icnludes
#include "../Core/ECS/World.h"
#include "../Core/ECS/Components/Camera2D.h"
#include "../Core/ECS/Components/Sprite.h"
#include "../Core/ECS/Components/Transfrom.h"
#include "../Core/ECS/Components/MeshRender.h"

/// <summary>
/// Actual Render System
/// Provide to render stuff on screen
/// </summary>
class SimpleRenderSystem
{
public:
	SimpleRenderSystem();

	void Init();

	void Update();

	void changeCurrentCamera();

	~SimpleRenderSystem();
private:
	Camera2D* m_current_camera;
	std::vector<Camera2D*> m_cameras;
};


class RenderSpriteSystem : public System
{
public:
	RenderSpriteSystem(Camera2D* m_current_camera);


	void Init();
	void Update(std::vector<BaseComponent*> components);
	void Render(std::vector<BaseComponent*> components);

	~RenderSpriteSystem();

private:

	Camera2D* m_current_camera;

};

#endif SIMPLERENDERSYSTEM_H