#include "Scene.h"
#include <iostream>


Scene::Scene()
{
	m_root = new SceneNode();
}


void Scene::Init_Scene()
{

	Init();
}
void Scene::Update_Scene(double dt)
{
	Update(dt);
}

void Scene::Render()
{
	SimpleRenderSystem::Render();
}

void Scene::Close_Scene()
{
	Close();
}



void Scene::addObject(SceneNode *node)
{
	node->init_this();
	m_root->atuch_children(node);
}
void Scene::addObjectTo(SceneNode *parentNode, SceneNode *node)
{

}
void Scene::removeObject(SceneNode *node)
{

}
void Scene::removeObjectFrom(SceneNode *parentNode, SceneNode *node)
{
}

SceneNode* Scene::get_Object(string name)
{
	return m_root->getChildren(name);
}


Scene::~Scene()
{
}
