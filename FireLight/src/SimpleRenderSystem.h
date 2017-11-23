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

	void Add(Renderable *rend);
	void remove(Renderable *rend);
	void Render();

	static void set_Camera(Camera *camera);
	static Camera* m_camera;

	~SimpleRenderSystem();
private:

	 std::vector<Renderable*> m_renderables;

};
#endif SIMPLERENDERSYSTEM_H