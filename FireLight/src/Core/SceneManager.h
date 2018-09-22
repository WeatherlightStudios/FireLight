#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
#include <map>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static void add_scene(Scene *scene, std::string name);

	static void set_current_scene(std::string name);
	static void init_current_scene();
	static void update_current_scene();

	static void render_current_scene();
	static void close_current_scene();

	static void change_current_scene_to(std::string name);


private:

	static Scene* m_current_scene;
	static std::map<std::string, Scene*> m_scenes;


};
#endif
