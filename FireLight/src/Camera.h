#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum projType
{
	ORTHO,
	PROSPECTIVE
};

class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch, projType projtype);
	void update();

	void translate(glm::vec3 trans);
	void rotate(float yaw, float pitch);

	void set_transform(glm::vec3 trans);
	void set_rotation(glm::vec3 rot);

	glm::vec3 get_forwardVec();
	glm::vec3 get_rightVec();

	glm::mat4 get_viewMatrix();
	glm::mat4 get_projectionMatrix();

	~Camera();
private:

	glm::vec3 m_position;
	glm::vec3 m_front;
	glm::vec3 m_right;
	glm::vec3 m_up;
	glm::vec3 m_worldUp;

	float m_yaw;
	float m_pitch;

	projType m_projType;
};