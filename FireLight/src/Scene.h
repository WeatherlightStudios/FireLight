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

	void addObject(SceneNode *node);
	void addObjectTo(SceneNode *parentNode, SceneNode *node);
	void removeObject(SceneNode *node);
	void removeObjectFrom(SceneNode *parentNode, SceneNode *node);

	SceneNode* get_Object(string name);

private:

	SceneNode *m_root;
};

#endif

