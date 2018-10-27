#include "Scene.h"
#include <iostream>



Scene::Scene()
{
	isInizialized = false;
}


void Scene::InitScene()
{
	
	//m_render_system.Init();
	Init();
	isInizialized = true;
}
void Scene::UpdateScene()
{
	Update();
}

void Scene::Render()
{
	//m_render_system.Update();
}

void Scene::CloseScene()
{
	Close();
}

Scene::~Scene()
{
}
