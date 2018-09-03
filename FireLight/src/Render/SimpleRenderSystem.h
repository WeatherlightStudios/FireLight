#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H
//prototype

#include <vector>
#include <algorithm>


#include "Renderable.h"
#include "Camera.h"
#include "Camera2D.h"

#include "../Core/ECS/World.h"
#include "../Core/ECS/Components/Camera2D.h"
#include "../Core/ECS/Components/Sprite.h"
#include "../Core/ECS/Components/Transfrom.h"

/// <summary>
/// Actual Render System
/// Provide to render stuff on screen
/// </summary>
class SimpleRenderSystem : public System
{
public:
	SimpleRenderSystem();

	//void Add(Renderable *rend);

	//void remove(Renderable *rend);

	void Init();

	void Update(std::vector<BaseComponent*> components);

	void Render(std::vector<BaseComponent*> components);


	~SimpleRenderSystem();
private:

	//Camera2D* m_camera;
	//std::vector<Renderable*> m_renderables;

};
#endif SIMPLERENDERSYSTEM_H