#include "Scene.h"



Scene::Scene()
{
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
	//m_rendersystem->Render();
}

void Scene::Close_Scene()
{
	Close();
}

Scene::~Scene()
{
}
