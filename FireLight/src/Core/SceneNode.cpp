#include "SceneNode.h"
#include <iostream>

std::map<std::string, SceneNode*>	SceneNode::m_nodes;


SceneNode::SceneNode()
{
	m_local_position = glm::vec3(0, 0, 0);
	m_local_scale = glm::vec3(1, 1, 1);
	m_local_rotation = 0;
}


void SceneNode::set_parent(SceneNode* parent)
{
	m_parent = parent;
}

SceneNode* SceneNode::Parent()
{
	return m_parent;
}

void SceneNode::destroy()
{
	m_parent->detuch_childern(this);
	destroyChildrens();
}

void SceneNode::destroyChildrens()
{
	std::vector<SceneNode*>::iterator it;
	for (it = m_childrens.begin(); it != m_childrens.end(); ++it)
	{
		(*it)->destroyChildrens();
		delete(*it);
	}
}

SceneNode *SceneNode::Children(std::string name)
{
	std::vector<SceneNode*>::iterator it;
	for (it = m_childrens.begin(); it != m_childrens.end(); ++it)
	{
		if ((*it)->Name() == name)
		{
			return (*it);
		}
		else
		{
			(*it)->Children(name);
		}
	}
}


void SceneNode::atuch_children(SceneNode* children)
{
	children->set_parent(this);
	m_childrens.push_back(children);
}

void atuch_children_to(SceneNode* parent, SceneNode* children)
{
	parent->atuch_children(children);
}

void SceneNode::detuch_childern(SceneNode* children)
{
	std::vector<SceneNode*>::iterator it;

	for (it = m_childrens.begin(); it != m_childrens.end(); ++it)
	{
		if ((*it) == children)
		{
			(*it)->set_parent(nullptr);
		}
	}
}

void SceneNode::init_this()
{
	init();
	init_children();
}

void SceneNode::init_children()
{
	std::vector<SceneNode*>::iterator it;

	for (it = m_childrens.begin(); it != m_childrens.end(); ++it)
	{
		(*it)->init_this();
	}

}

void SceneNode::setName(std::string name)
{
	m_name = name;
}

void SceneNode::update_this(double dt)
{
	update(dt);
	update_children(dt);
}

void SceneNode::update_children(double dt)
{
	std::vector<SceneNode*>::iterator it;

	for (it = m_childrens.begin(); it != m_childrens.end(); ++it)
	{
		(*it)->update_this(dt);
	}
}

void SceneNode::set_position(glm::vec3 pos)
{
	m_local_position = pos;
}

void SceneNode::set_scale(glm::vec3 scale)
{
	m_local_scale = scale;
}

void SceneNode::set_position(float x, float y, float z)
{
	m_local_position = glm::vec3(x ,y ,z);
}

void SceneNode::set_scale(float x, float y, float z)
{
	m_local_scale = glm::vec3(x, y, z);
}


void SceneNode::set_rotation(float rot)
{
	m_local_rotation = rot;
}

void SceneNode::translate(glm::vec3 pos) 
{
	m_local_position += pos;
}
void SceneNode::scale(glm::vec3 scale)
{
	m_local_scale += scale;
}

void SceneNode::translate(float x, float y, float z)
{
	m_local_position += glm::vec3(x, y, z);
}
void SceneNode::scale(float x, float y, float z)
{
	m_local_scale += glm::vec3(x, y, z);
}

void SceneNode::rotate(float rot)
{
	m_local_rotation += rot;
}

void SceneNode::setDefaultScale(glm::vec3 scale)
{
	m_default_scale = scale;
}

SceneNode::~SceneNode()
{
}
