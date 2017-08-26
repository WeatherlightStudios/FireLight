#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
	void Update();

	void Translate(glm::vec3 transform);
	void Rotate(float Yaw, float Pitch);

	glm::vec3 get_VectorForward();
	glm::vec3 get_VectorRight();

	glm::mat4 get_ViewMatrix();
	glm::mat4 getCameraProjection();



	~Camera();
private:

	glm::vec3 m_Position;
	glm::vec3 m_Front;
	glm::vec3 m_Right;
	glm::vec3 m_Up;
	glm::vec3 m_WorldUp;

	float m_Yaw;
	float m_Pitch;

	float m_sensitivity;
};

