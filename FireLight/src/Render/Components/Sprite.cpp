#include "Sprite.h"

#include <iostream>


Sprite::Sprite()
{

}

Sprite::Sprite(Texture tex, glm::vec2 rows, glm::vec2 offset):
	m_texture(tex), m_row(rows), m_offset(offset)
{
}

void Sprite::Debug()
{

}

Sprite::~Sprite()
{
}
