#include "SceneNode.h"



SceneNode::SceneNode()
{

}


void SceneNode::set_parent(SceneNode* parent)
{
	m_parent = parent;
}

SceneNode* SceneNode::get_parent()
{
	return m_parent;
}

void SceneNode::atuch_children(SceneNode* children)
{
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
			(*it)->set_parent(m_root);
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
		(*it)->init();
	}

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

void SceneNode::set_local_position(glm::vec3 pos)
{
	m_local_position = pos;
}

void SceneNode::set_local_scale(glm::vec3 scale)
{
	m_local_scale = scale;
}

void SceneNode::set_local_rotation(float rot)
{
	m_local_rotation = rot;
}


SceneNode::~SceneNode()
{
}
