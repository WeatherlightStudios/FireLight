#include "Camera2D.h"

glm::vec3 Camera2D::m_position = glm::vec3(0, 0, -1);
float Camera2D::m_rotation = 0.0f;


Camera2D::Camera2D()
{

}


glm::mat4 Camera2D::getMatrix()
{


	glm::mat4 projection = glm::ortho(800.0f / -600.0f, 800.0f / 600.0f, -1.0f, 1.0f, 0.001f, 10000.0f);
	glm::mat4 orientation;
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation, m_rotation, glm::vec3(0, 0, 1));
	projection *= orientation;
	projection = glm::translate(projection, m_position);
	return projection;
}



void Camera2D::rotate(float rotation_ammount)
{
	m_rotation += rotation_ammount;
}
void Camera2D::translate(glm::vec3 pos_ammount)
{
	m_position += pos_ammount;
}
void Camera2D::set_position(glm::vec3 pos)
{
	m_position = pos;
}


void Camera2D::set_rotation(float rotation)
{
	m_rotation = rotation;
}



Camera2D::~Camera2D()
{

}
