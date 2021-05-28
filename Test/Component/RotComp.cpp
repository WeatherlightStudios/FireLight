#include "RotComp.h"


RotComp::RotComp()
{

}

void RotComp::Init()
{ 

}

void RotComp::Update()
{
	x+=0.01;
	GetOwner()->GetComponent<Transform>()->SetRotation(glm::vec3(0,x,0));
}

RotComp::~RotComp()
{

}
