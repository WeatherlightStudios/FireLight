#ifndef SCENE_H
#define SCENE_H

#include "SceneNode.h"
#include "SimpleRenderSystem.h"
#include "Renderable.h"
#include <vector>
#include <string>

using namespace std;

class Scene
{
public:
	Scene();
	~Scene();


	void init_scene();
	void update_scene(double dt);
	void render();
	void close_scene();

	virtual void Init(){}
	virtual void CameraUpdate(Camera *camera) {}
	virtual void Update(double dt){}
	virtual void Debug(){}
	virtual void Close(){}

	void add_object(SceneNode *node);
	//void add_objectTo(SceneNode *parentNode, SceneNode *node);
	void remove_object(SceneNode *node);
	//void remove_objectFrom(SceneNode *parentNode, SceneNode *node);

	void init_objects();
	void init_render();
	void check_renderable_node(SceneNode* node);


	SceneNode* get_object(string name);

private:
	bool isInizialized;


	SimpleRenderSystem m_render_system;
	std::vector<SceneNode*> m_graph_objects;
	Camera *m_camera;
};

#endif

