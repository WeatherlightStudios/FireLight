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
	m_current_scene->init_scene();
}

void SceneManager::init_current_scene()
{
	if (m_current_scene != nullptr)
		m_current_scene->init_scene();
}
void SceneManager::update_current_scene(double dt)
{
	if (m_current_scene != nullptr)
		m_current_scene->update_scene(dt);

}
void SceneManager::render_current_scene()
{
	if (m_current_scene != nullptr)
		m_current_scene->render();
}

void SceneManager::close_current_scene()
{
	if (m_current_scene != nullptr)
		m_current_scene->Close();
}

void SceneManager::change_current_scene_to(std::string name)
{
	SceneManager::close_current_scene();
	m_current_scene = m_scenes[name];
	SceneManager::init_current_scene();
}

SceneManager::~SceneManager()
{
}
