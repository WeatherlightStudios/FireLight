#include "Transform.h"


Transform::Transform():
	m_position(glm::vec3(0,0,0)), m_rotation(glm::vec3(0, 0, 0)), m_scale(glm::vec3(1, 1, 1))
{
	FL::LOG_INFO_ENGINE("Transform is inizialized without constructor");

}

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) :
	m_position(pos), m_rotation(rot), m_scale(scale)
{
	FL::LOG_INFO_ENGINE("Transform is inizialized without constructor");
	m_position = pos;
	m_rotation = rot;
	m_scale = scale;
}


void Transform::Init()
{

}

void Transform::Update()
{

}
void Transform::Debug()
{



	//ImGui::Text("Position");
	//ImGui::InputFloat("X Position: ", &m_position.x); ImGui::SameLine();
	//ImGui::InputFloat("Y Position: ", &m_position.y);


	//ImGui::Text("Scale");
	//ImGui::InputFloat("X: ", &m_scale.x); ImGui::SameLine();
	//ImGui::InputFloat("Y: ", &m_scale.y);
}

Transform::~Transform()
{

}