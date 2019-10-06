#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../../Core/Component.h"
#include "../../../imgui/imgui.h"
#include <glm/glm.hpp>

class Transform : public Component
{
public:
	Transform();
	Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);


	void SetPosition(glm::vec3 pos) { m_position = pos; }
	void SetScale(glm::vec3 scale) { m_scale = scale; }
	void SetRotation(glm::vec3 rot) { m_rotation = rot; }

	glm::vec3 GetPosition() { return m_position; }
	glm::vec3 GetScale() { return m_scale; }
	glm::vec3 GetRotation() { return m_rotation; }

	void Init();
	void Update();
	void Debug();

	~Transform();

private: 

	glm::vec3 m_position;
	glm::vec3 m_scale;
	glm::vec3 m_rotation;


};

#endif // ! 