#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../../Core/Component.h"
#include "../../../imgui/imgui.h"
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../Utility/Debugging/Log.h"

class Transform : public Component
{
public:
	Transform();
	Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);


	void SetPosition(glm::vec3 pos) { 
		m_position = pos; 
		m_transform_matrix = glm::translate(glm::mat4(1.0f), m_position);
	}
	void SetScale(glm::vec3 scale) {
		m_scale = scale; 
		m_scale_matrix = glm::scale(glm::mat4(1.0f), m_scale);
	}
	void SetRotation(glm::vec3 rot) { 
		m_rotation = rot; 
		m_rotation_matrix = glm::toMat4(glm::quat(m_rotation));
	}

	glm::vec3 GetPosition() { return m_position; }
	glm::vec3 GetScale() { return m_scale; }
	glm::vec3 GetRotation() { return m_rotation; }

	glm::mat4 GetMatrix();

	void Init();
	void Update();
	void Debug();

	~Transform();

private: 

	glm::vec3 m_position;
	glm::vec3 m_scale;
	glm::vec3 m_rotation;

	glm::mat4 m_rotation_matrix;
	glm::mat4 m_transform_matrix;
	glm::mat4 m_scale_matrix;

};

#endif // ! 