#include "FPSCamera.h"



FPSCamera::FPSCamera()
{
	registerComponent(Transform::ID);
	registerComponent(Camera3D::ID);
}


void FPSCamera::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	Camera3D* camera3D = World::getComponent<Camera3D>(entity);


	float velocity = 5.0f;
	float rotVelocity = 100.0f;
	//transform->Position *= transform->Rotation;

	if (FL::Window::isKeyPress(KEYCODE::KEY_W))
	{

		transform->Position += camera3D->forward * velocity * (float)Time::GetDeltaTime();
	}

	if (FL::Window::isKeyPress(KEYCODE::KEY_S))
	{
		transform->Position += camera3D->forward * -velocity * (float)Time::GetDeltaTime();
	}

	if (FL::Window::isKeyPress(KEYCODE::KEY_A))
	{
		transform->Position += camera3D->left * velocity * (float)Time::GetDeltaTime();
	}

	if (FL::Window::isKeyPress(KEYCODE::KEY_D))
	{
		transform->Position += camera3D->left * -velocity * (float)Time::GetDeltaTime();
	}

	glm::vec2 mousePos = FL::Window::get_mouse_positions();

	//float offsetX = (mousePos.x - FL::Window::getWidth() / 2);
	//float offsetY = (FL::Window::getHeight() / 2 - mousePos.y);

	glm::vec2 mouse_delta = glm::vec2(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2) - mousePos;


	transform->Rotation += glm::vec3(-mouse_delta.y, -mouse_delta.x,0);

	FL::Window::setCursorPosition(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2);


}

FPSCamera::~FPSCamera()
{
}
