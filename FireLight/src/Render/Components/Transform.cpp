#include "Transform.h"


Transform::Transform():
	m_position(glm::vec2(0,0)), m_rotation(0.0f), m_scale(glm::vec2(1,1))
{
}

Transform::Transform(glm::vec2 pos, float rot, glm::vec2 scale) :
	m_position(pos), m_rotation(rot), m_scale(scale)
{
}

Transform::Transform(glm::vec2 pos) :
	m_position(pos), m_rotation(0.0f), m_scale(glm::vec2(1,1))
{
}

Transform::Transform(glm::vec2 pos, float rot) :
	m_position(pos), m_rotation(rot), m_scale(glm::vec2(1, 1))
{
}

Transform::Transform(glm::vec2 pos, glm::vec2 scale) :
	m_position(pos), m_rotation(0.0f), m_scale(scale)
{
}


void Transform::Init()
{

}

void Transform::Update()
{

}
void Transform::Debug()
{



	ImGui::Text("Position");
	ImGui::InputFloat("X Position: ", &m_position.x); ImGui::SameLine();
	ImGui::InputFloat("Y Position: ", &m_position.y);


	ImGui::Text("Scale");
	ImGui::InputFloat("X: ", &m_scale.x); ImGui::SameLine();
	ImGui::InputFloat("Y: ", &m_scale.y);
}

Transform::~Transform()
{

}