#include "Transform.h"


Transform::Transform()
{

}

Transform::Transform(glm::vec2 pos, glm::vec2 scale, float rot)
{
	m_position = pos;
	m_scale = scale;
	m_rotation = rot;
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