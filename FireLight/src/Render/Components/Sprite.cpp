#include "Sprite.h"

#include <iostream>


Sprite::Sprite()
{
	m_position = glm::vec2(0, 0);
	m_scale = glm::vec2(1, 1);
	m_rotation = 0.0f;
}


void Sprite::Init()
{

}


void Sprite::Update()
{

}

void Sprite::Debug()
{
	int rowX  = m_row.x;
	int rowY = m_row.y;

	int ofssetX = m_offset.x;
	int ofssetY = m_offset.y;


	float x;
	float y;

	float rot;

	float scaleX = m_scale.x;
	float scaleY = m_scale.y;

	ImGui::Begin("SpriteDebug");

	ImGui::InputFloat("sclaeX", &scaleX);
	ImGui::InputFloat("sclaeY", &scaleY);



	ImGui::SliderInt("RowX", &rowX, 0, 100);
	ImGui::SliderInt("RowY", &rowY, 0, 100);

	ImGui::SliderInt("offsetX", &ofssetX, 0, 100);
	ImGui::SliderInt("offsetY", &ofssetY, 0, 100);

	ImGui::End();


	m_row = glm::vec2(rowX, rowY);
	m_offset = glm::vec2(ofssetX, ofssetY);

	m_scale = glm::vec2(scaleX, scaleY);



}

Sprite::~Sprite()
{
}
