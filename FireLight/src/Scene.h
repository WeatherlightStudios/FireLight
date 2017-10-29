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


	void Init_Scene();
	void Update_Scene(double dt);
	void Render();
	void Close_Scene();

	virtual void Init(){}
	virtual void Update(double dt){}
	virtual void Close(){}

	void addObject();
	void removeObject();



	SceneNode* get_node(string name);



private:

	SceneNode *m_root;
	//FL::Graphic::SimpleRenderSystem *m_rendersystem;
	std::vector<Renderable> m_renderable_objects;

};

#endif

