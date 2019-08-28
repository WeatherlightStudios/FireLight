#include "FPSCamera.h"



FPSCamera::FPSCamera()
{
	registerComponent(Transform::ID);
	registerComponent(Camera3D::ID);
	isEnabled = true;
}


void FPSCamera::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	Camera3D* cam = World::getComponent<Camera3D>(entity);

	//clamp cam speed to be > 0
	cam->velocity = glm::max(cam->velocity, 0.0f);
	auto speed = cam->velocity;

	if (FL::Window::isKeyPress(KEYCODE::KEY_LEFT_SHIFT)) {
		speed = cam->velocity * cam->speedMultiplier;
	}

	////CAMERA MOVEMENT

	if (FL::Window::isKeyPress(KEYCODE::KEY_W))
	{
		transform->Position += cam->forward * speed * (float)Time::GetDeltaTime();
	}

	if (FL::Window::isKeyPress(KEYCODE::KEY_S))
	{
		transform->Position += cam->forward * -speed * (float)Time::GetDeltaTime();
	}

	if (FL::Window::isKeyPress(KEYCODE::KEY_A))
	{
		transform->Position += cam->left * speed * (float)Time::GetDeltaTime();
	}

	if (FL::Window::isKeyPress(KEYCODE::KEY_D))
	{
		transform->Position += cam->left * -speed * (float)Time::GetDeltaTime();
	}

	////CAMERA ROTATION
	if (FL::Window::isKeyDown(KEYCODE::KEY_ESCAPE))
	{
		isEnabled = !isEnabled;
	}

	if (isEnabled) {
		glm::vec2 mousePos = FL::Window::get_mouse_positions();

		glm::vec2 mouse_delta = glm::vec2(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2) - mousePos;

		transform->Rotation += glm::vec3(-mouse_delta.y, -mouse_delta.x,0) * cam->rotVelocity;

		FL::Window::setCursorPosition(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2);
	}
}

FPSCamera::~FPSCamera()
{
}
