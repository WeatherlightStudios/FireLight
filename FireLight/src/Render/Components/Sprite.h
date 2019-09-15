#ifndef SPRITE_H
#define SPRITE_H

#include "../../Core/Component.h"
#include <glm/glm.hpp>


class Sprite : public Component
{
public:
	Sprite();

	//void SetPosition(glm::vec2 position);
	//void SetRotation(float rotation);
	//void SetScale(glm::vec2 scale);

	glm::vec2 GetPosition() { return m_position; }
	glm::vec2 GetScale() { return m_scale; }
	float GetRotation() { return m_rotation; }

	void Init();
	void Update();

	~Sprite();


private:

	glm::vec2 m_position;
	glm::vec2 m_scale;
	float m_rotation;


};

#endif