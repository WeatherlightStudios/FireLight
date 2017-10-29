#include "SceneNode.h"
#include "Renderable.h"

std::map<std::string, SceneNode*>	SceneNode::m_nodes;
std::vector<Renderable*>			SceneNode::m_renderable_objects;
SceneNode*							SceneNode::m_root;


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

void SceneNode::destroy()
{
	m_parent->detuch_childern(this);
	if (dynamic_cast<const Renderable*>(this)) 
	{
		m_renderable_objects.erase(std::find(m_renderable_objects.begin(), m_renderable_objects.end(),(Renderable*)this)); 
	}
	std::vector<SceneNode*>::iterator it;
	for (it = m_childrens.begin(); it != m_childrens.end(); ++it)
	{
		if (dynamic_cast<const Renderable*>(*it))
		{
			m_renderable_objects.erase(std::find(m_renderable_objects.begin(), m_renderable_objects.end(), (Renderable*)*it));
		}
		delete(*it);
	}
	delete(this);
}

void SceneNode::atuch_children(SceneNode* children)
{
	children->set_parent(this);
	children->init_this();
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
	if (dynamic_cast<const Renderable*>(this)){	m_renderable_objects.push_back((Renderable*)this);}
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
