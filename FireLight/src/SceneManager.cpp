#include "SceneManager.h"


std::map<std::string, Scene*>	SceneManager::m_scenes;
Scene* SceneManager::m_current_scene;

SceneManager::SceneManager()
{
}

void SceneManager::add_scene(Scene* scene, std::string name)
{
	m_scenes[name] = scene;
}

void SceneManager::set_current_scene(std::string name)
{
	m_current_scene = m_scenes[name];
}

void SceneManager::init_current_scene()
{
	m_current_scene->Init_Scene();
}
void SceneManager::update_current_scene(double dt)
{
	m_current_scene->Update_Scene(dt);
}
void SceneManager::render_current_scene()
{
	m_current_scene->Render();
}
void SceneManager::close_current_scene()
{
	m_current_scene->Close();
}

void SceneManager::change_current_scene(std::string name)
{
	SceneManager::close_current_scene();
	m_current_scene = m_scenes[name];
	SceneManager::init_current_scene();

}

SceneManager::~SceneManager()
{
}
