#include "Camera.h"
#include <iostream>


Camera::Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.f, float pitch = 0.f, projType projtype = projType::PROSPECTIVE)
{
	m_position = position;
	m_projType = projtype;
	m_worldUp = up;
	m_pitch = pitch;
	m_yaw = yaw;

	update();
}

void Camera::update()
{
	glm::vec3 front;

	front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	front.y = sin(glm::radians(m_pitch));
	front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

	m_front = glm::normalize(front);
	m_right = glm::normalize(glm::cross(m_front, m_worldUp));
	m_up	= glm::normalize(glm::cross(m_right, m_front));

	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	if (m_pitch < -89.0f)
		m_pitch = -89.0f;


}

void Camera::translate(glm::vec3 trans)
{
	m_position += trans;
}

void Camera::rotate(float yaw, float pitch)
{
	m_yaw += yaw;
	m_pitch += pitch;
}

void Camera::set_transform(glm::vec3 trans)
{
	m_position = trans;
}
void Camera::set_rotation(glm::vec3 rot)
{
	m_yaw = rot.x;
	m_pitch = rot.y;
}

glm::vec3 Camera::get_forwardVec()
{
	return m_front;
}

glm::vec3 Camera::get_rightVec()
{
	return m_right;
}

glm::vec3 Camera::get_cameraPos() {
	return m_position;
}

glm::mat4 Camera::get_viewMatrix()
{
	return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::mat4 Camera::get_projectionMatrix()
{
	if (m_projType == projType::PROSPECTIVE)
	{
		return glm::perspective(glm::radians(60.f), 800.f / 600.f, 0.1f, 10000.f);
	}
	else if (m_projType == projType::ORTHO)
	{
		return glm::ortho(800.0f / 600.0f, -800.0f / 600.0f, -1.0f, 1.0f,0.001f,10000.0f); 
	}
	else
	{
		return glm::perspective(glm::radians(60.f), 800.f / 600.f, 0.1f, 10000.f);
	}
}

Camera::~Camera()
{

}