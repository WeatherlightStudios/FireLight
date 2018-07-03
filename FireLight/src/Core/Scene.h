#ifndef SCENE_H
#define SCENE_H

#include "SceneNode.h"
#include "../Render/SimpleRenderSystem.h"
#include "../Utility/Debug.h"
#include "../Render/Renderable.h"
#include "../Render/Camera2D.h"
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
	virtual void Update(){}
	virtual void Debughing(Debug *debug){}
	virtual void Close(){}

	void add_object(SceneNode &node);
	//void add_objectTo(SceneNode *parentNode, SceneNode *node);
	void remove_object(SceneNode &node);
	//void remove_objectFrom(SceneNode *parentNode, SceneNode *node);

	void update_objects(double dt);
	void add_renderable_node(SceneNode &node);
	void remove_renderable_node(SceneNode &node);

	SceneNode* get_object(string name);

private:
	bool isInizialized;

	Debug *m_debug;
	SimpleRenderSystem m_render_system;
	std::vector<SceneNode*> m_graph_objects;
	Camera *m_camera;
	Camera2D *m_camera2D;
};

#endif