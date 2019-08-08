#include "PlayerMovement_S.h"



PlayerMovement_S::PlayerMovement_S()
{
	registerComponent(Transform::ID);
	registerComponent(PlayerMovement::ID);

}

void PlayerMovement_S::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	PlayerMovement* movement = World::getComponent<PlayerMovement>(entity);



	if (FL::Window::isKeyPress(GLFW_KEY_W))
	{
		transform->Position.y += movement->Speed * Time::GetDeltaTime();
	}
	if (FL::Window::isKeyPress(GLFW_KEY_S))
	{
		transform->Position.y -= movement->Speed * Time::GetDeltaTime();

	}
	if (FL::Window::isKeyPress(GLFW_KEY_A))
	{
		transform->Position.x -= movement->Speed * Time::GetDeltaTime();

	}
	if (FL::Window::isKeyPress(GLFW_KEY_D))
	{
		transform->Position.x += movement->Speed * Time::GetDeltaTime();

	}

}


PlayerMovement_S::~PlayerMovement_S()
{
}
