#ifndef SCENE_H
#define SCENE_H

#include "SceneNode.h"
#include "SimpleRenderSystem.h"
#include <string>

using namespace std;

class Scene
{
public:
	Scene();
	~Scene();


	void Init_Scene();
	void Update_Scene(double dt);
	void Close_Scene();

	virtual void Init(){}
	virtual void Update(double dt){}
	virtual void Close(){}

	void instantiate_node(SceneNode* node, string node_name);
	void detuch_node(string node_name);
	void destroy_node(string node_name);

	SceneNode* get_node(string name);



private:

	SceneNode *m_root;
	FL::Graphic::SimpleRenderSystem *m_rendersystem;
	

};

#endif

