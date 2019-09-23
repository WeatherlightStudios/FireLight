#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../../Core/Component.h"
#include "../../../imgui/imgui.h"
#include <glm/glm.hpp>

class Transform : public Component
{
public:
	Transform();
	Transform(glm::vec2 pos);
	Transform(glm::vec2 pos, float rot);
	Transform(glm::vec2 pos, glm::vec2 scale);
	Transform(glm::vec2 pos, float rot, glm::vec2 scale);


	void SetPosition(glm::vec2 pos) { m_position = pos; }
	void SetScale(glm::vec2 scale) { m_scale = scale; }
	void SetRotation(float rot) { m_rotation = rot; }

	glm::vec2 GetPosition() { return m_position; }
	glm::vec2 GetScale() { return m_scale; }
	float GetRotation() { return m_rotation; }

	void Init();
	void Update();
	void Debug();

	~Transform();

private: 

	glm::vec2 m_position;
	glm::vec2 m_scale;
	float m_rotation;


};

#endif // ! 