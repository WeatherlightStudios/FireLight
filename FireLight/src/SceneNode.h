#ifndef SCENENODE_H
#define SCENENODE_H


#include <glm\vec3.hpp>
#include <glm\vec4.hpp>

#include <string>
#include <memory>
#include <map>
#include <vector>

class Renderable;

class SceneNode
{
public:


	SceneNode();
	~SceneNode();
	
	void set_parent(SceneNode* parent);
	SceneNode* get_parent();

	void atuch_children(SceneNode* children);
	void detuch_childern(SceneNode* children);

	SceneNode* getChildren(std::string name) { return m_nodes[name]; }

	virtual void init() {}
	virtual void update(double dt) {}

	void destroy();
	void destroyChildrens();

	void init_this();
	void init_children();

	void update_this(double dt);
	void update_children(double dt);


	void set_local_position(glm::vec3 pos);
	void set_local_scale(glm::vec3 scale);
	void set_local_rotation(float rot);


	glm::vec3 get_local_position() { return m_local_position; }
	glm::vec3 get_world_position() { return m_parent != nullptr ? m_parent->get_world_position() + m_local_position : m_local_position; }

	glm::vec3 get_local_scale() { return m_local_scale; }
	glm::vec3 get_world_scale() { return m_parent != nullptr ? m_parent->get_world_scale() + m_local_scale : m_local_scale; }

	float get_local_rotation() { return m_local_rotation; }
	//TODO: Da sistemare!
	float get_world_rotation() { return m_world_rotation; }

private:

	glm::vec3 m_local_position;
	glm::vec3 m_world_position;

	glm::vec3 m_local_scale;
	glm::vec3 m_world_scale;

	float m_local_rotation;
	float m_world_rotation;



	static SceneNode* m_root;
	SceneNode* m_parent;
	std::vector<SceneNode*> m_childrens;
	static std::map<std::string ,SceneNode*> m_nodes;

};

#endif

