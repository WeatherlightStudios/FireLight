#include "Scene.h"
#include <iostream>



Scene::Scene()
{
	isInizialized = false;
	m_camera = new Camera(glm::vec3(0, 0, -3), glm::vec3(0, 1, 0), 90, 0, projType::ORTHO);
	m_camera2D = new Camera2D();
	m_debug = new Debug();
}


void Scene::init_scene()
{
	
	Init();
	m_render_system.set_Camera(m_camera2D);
	m_debug->create();
	m_debug->setCamera(m_camera);
	isInizialized = true;
	//std::cout << m_graph_objects.size() << std::endl;
}
void Scene::update_scene(double dt)
{
	m_camera->update();
	CameraUpdate(m_camera);
	update_objects(dt);
	Update(dt);

	//std::cout << m_graph_objects.size() << endl;
}

void Scene::render()
{
	m_render_system.Render();
}

void Scene::update_objects(double dt)
{
	for (int i = 0; i < m_graph_objects.size(); i++)
	{
		m_graph_objects[i]->update_this(dt);
	}
}

void Scene::add_renderable_node(SceneNode &node)
{
	if (dynamic_cast<Renderable*>(&node))
	{
		m_render_system.Add(dynamic_cast<Renderable*>(&node));

		//test
		for (int i = 0; i < node.get_children_size(); i++)
		{
			add_renderable_node(*node.getChildren(i));
		}
	}
	else
	{
		for (int i = 0; i < node.get_children_size(); i++)
		{
			add_renderable_node(*node.getChildren(i));
		}
	}
}

void Scene::remove_renderable_node(SceneNode &node)
{
	if (dynamic_cast<const Renderable*>(&node))
	{
		for (int i = 0; i < node.get_children_size(); i++)
		{
			remove_renderable_node(*node.getChildren(i));
		}
	}
	else
	{
		m_render_system.remove((Renderable*)&node);

		//test
		for (int i = 0; i < node.get_children_size(); i++)
		{
			remove_renderable_node(*node.getChildren(i));
		}
	}
}

void Scene::close_scene()
{
	Close();
}

void Scene::add_object(SceneNode &node)
{
	m_graph_objects.push_back(&node);
	node.init_this();
	add_renderable_node(node);
}

void Scene::remove_object(SceneNode &node)
{
	for (int i = 0; i < m_graph_objects.size(); ++i)
	{
		if (m_graph_objects[i] == &node)
		{
			remove_renderable_node(*m_graph_objects[i]);
			m_graph_objects.erase(m_graph_objects.begin() + (i));
		}
	}

}

SceneNode* Scene::get_object(string name)
{
	for (int i = 0; i < m_graph_objects.size(); ++i)
	{
		return m_graph_objects[i]->getChildren(name);
	}
}


Scene::~Scene()
{
}
