#include "Transform.h"


Transform::Transform():
	m_position(glm::vec3(0,0,0)), m_rotation(glm::vec3(0, 0, 0)), m_scale(glm::vec3(1, 1, 1))
{
	FL::LOG_INFO_ENGINE("Transform is inizialized without constructor");
	SetPosition(m_position);
	SetRotation(m_rotation);
	SetScale(m_scale);
}

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale) :
	m_position(pos), m_rotation(rot), m_scale(scale)
{
	FL::LOG_INFO_ENGINE("Transform is inizialized without constructor");
	SetPosition(pos);
	SetRotation(rot);
	SetScale(scale);
}

void Transform::Init()
{

}

void Transform::Update()
{

}
void Transform::Debug()
{

}


glm::mat4 Transform::GetMatrix()
{
	return m_transform_matrix * m_rotation_matrix * m_scale_matrix;
}

Transform::~Transform()
{

}