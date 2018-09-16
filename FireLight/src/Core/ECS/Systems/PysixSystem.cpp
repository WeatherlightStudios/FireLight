#include "PysixSystem.h"



PysixSystem::PysixSystem()
{
}

void PysixSystem::Init()
{
	registerComponent<Transform>();
	registerComponent<PhysicsBody>();
}

void PysixSystem::Update(std::vector<BaseComponent*> components)
{
	Transform* transform = (Transform*)components[0];
	PhysicsBody* PhyBody = (PhysicsBody*)components[1];

	transform->position = glm::vec3(PhyBody->body->GetPosition().x, PhyBody->body->GetPosition().y, 0.0f);

}


PysixSystem::~PysixSystem()
{
}
