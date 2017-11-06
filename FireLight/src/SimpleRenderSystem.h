#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H
//prototype

#include <vector>
#include "Renderable.h"
#include "Camera.h"


class SimpleRenderSystem
{
public:
	SimpleRenderSystem();

	static void Add(Renderable *rend);
	static void remove(Renderable *rend);
	static void Render();

	static void set_Camera(Camera *camera);
	static Camera* m_camera;

	~SimpleRenderSystem();
private:

	static std::vector<Renderable*> m_renderables;

};
#endif SIMPLERENDERSYSTEM_H