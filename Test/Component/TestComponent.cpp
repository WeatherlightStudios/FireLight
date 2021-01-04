#include "TestComponent.h"

void TestComponent::Init()
{
	FL::Window::SetCursorPosition(FL::Window::GetWidth() / 2, FL::Window::GetHeight() / 2);
}

void TestComponent::Update()
{
	auto transform = m_Owner->GetComponent<Transform>();
	auto camera = m_Owner->GetComponent<Camera>();

	if (FL::Input::IsKeyPress(FL::KEYCODE::KEY_W))
	{
		transform->SetPosition(transform->GetPosition() + (camera->forward * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::IsKeyPress(FL::KEYCODE::KEY_S))
	{
		transform->SetPosition(transform->GetPosition() - (camera->forward * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::IsKeyPress(FL::KEYCODE::KEY_A))
	{
		transform->SetPosition(transform->GetPosition() + (camera->left * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::IsKeyPress(FL::KEYCODE::KEY_D))
	{
		transform->SetPosition(transform->GetPosition() - (camera->left * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::IsKeyPress(FL::KEYCODE::KEY_Q))
	{
		transform->SetPosition(transform->GetPosition() - (camera->upward * velocity * (float)Time::GetDeltaTime()));
	}


	if (FL::Input::IsKeyPress(FL::KEYCODE::KEY_E))
	{
		transform->SetPosition(transform->GetPosition() + (camera->upward * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::IsKeyDown(FL::KEYCODE::KEY_ESCAPE))
	{
		FL::Window::SetCursorPosition(FL::Window::GetWidth() / 2, FL::Window::GetHeight() / 2);
		isCameraUsed = !isCameraUsed;
	}

	if (isCameraUsed)
	{
		FL::Window::SetCursorPosition(FL::Window::GetWidth() / 2, FL::Window::GetHeight() / 2);
		glm::vec2 mousePos = FL::Window::get_mouse_positions();
		glm::vec2 mouse_delta = glm::vec2(FL::Window::GetWidth() / 2, FL::Window::GetHeight() / 2) - mousePos;
		transform->SetRotation(transform->GetRotation() + glm::vec3(-mouse_delta.y * Time::GetDeltaTime() * mouse_velocity, -mouse_delta.x * Time::GetDeltaTime() * mouse_velocity, 0));
	}

}
