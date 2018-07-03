#ifndef SCENENODE_H
#define SCENENODE_H


#include <glm\vec3.hpp>
#include <glm\vec4.hpp>

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

class SceneNode
{
public:

	
	SceneNode();
	~SceneNode();
	
	void set_parent(SceneNode* parent);
	SceneNode* Parent();

	void atuch_children(SceneNode* children);
	void detuch_childern(SceneNode* children);



	void destroy();
	void destroyChildrens();

	virtual void update(double dt) {}
	virtual void init() { std::cout << "INIT"; }

	void init_this();
	void init_children();

	void update_this(double dt);
	void update_children(double dt);

	size_t children_size() { return m_childrens.size(); }
	SceneNode *Children(size_t i) { return m_childrens[i]; }
	SceneNode *Children(std::string name);

	void setName(std::string name);
	std::string Name() { return m_name; }

	

	//More deep Refactoring 
	// transformation and math stuff
	void set_position(glm::vec3 pos);
	void set_scale(glm::vec3 scale);
	void set_position(float x, float y, float z);
	void set_scale(float x, float y, float z);
	void set_rotation(float rot);

	void translate(glm::vec3 pos);
	void scale(glm::vec3 scale);
	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	void rotate(float rot);

	void setDefaultScale(glm::vec3 scale);


	glm::vec3 local_position() { return m_local_position; }
	glm::vec3 world_position() { return m_parent != nullptr ? m_parent->world_position() + m_local_position : m_local_position; }

	glm::vec3 local_scale() { return m_local_scale * m_default_scale; }
	glm::vec3 world_scale() { return m_parent != nullptr ? m_parent->world_scale() * local_scale() : local_scale(); }

	float local_rotation() { return m_local_rotation; }
	float world_rotation() { return m_parent != nullptr ? m_parent->world_rotation() + m_local_rotation : m_local_rotation; }

private:

	std::string m_name;

	glm::vec3 m_local_position;
	glm::vec3 m_world_position;



	glm::vec3 m_default_scale;
	glm::vec3 m_local_scale;
	glm::vec3 m_world_scale;

	float m_local_rotation;
	float m_world_rotation;





	SceneNode* m_parent;
	std::vector<SceneNode*> m_childrens;
	static std::map<std::string ,SceneNode*> m_nodes;

};

#endif

