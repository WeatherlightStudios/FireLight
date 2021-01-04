#include "Moviment.h"

void Moviment::Init() 
{

}

void Moviment::Update()
{
	m_Owner->GetComponent<Transform>()->SetPosition(glm::vec3(sin(Time::GetTime()),1.0f, cos(Time::GetTime())));
}
