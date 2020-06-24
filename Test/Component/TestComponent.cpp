#include "TestComponent.h"

void TestComponent::Init()
{
	FL::Window::setCursorPosition(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2);
}

void TestComponent::Update()
{
	auto transform = m_Owner->GetComponent<Transform>();
	auto camera = m_Owner->GetComponent<Camera>();

	if (FL::Input::isKeyPress(FL::KEYCODE::KEY_W))
	{
		transform->SetPosition(transform->GetPosition() + (camera->forward * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::isKeyPress(FL::KEYCODE::KEY_S))
	{
		transform->SetPosition(transform->GetPosition() - (camera->forward * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::isKeyPress(FL::KEYCODE::KEY_A))
	{
		transform->SetPosition(transform->GetPosition() + (camera->left * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::isKeyPress(FL::KEYCODE::KEY_D))
	{
		transform->SetPosition(transform->GetPosition() - (camera->left * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::isKeyPress(FL::KEYCODE::KEY_Q))
	{
		transform->SetPosition(transform->GetPosition() - (camera->upward * velocity * (float)Time::GetDeltaTime()));
	}


	if (FL::Input::isKeyPress(FL::KEYCODE::KEY_E))
	{
		transform->SetPosition(transform->GetPosition() + (camera->upward * velocity * (float)Time::GetDeltaTime()));
	}

	if (FL::Input::isKeyDown(FL::KEYCODE::KEY_ESCAPE))
	{
		FL::Window::setCursorPosition(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2);
		isCameraUsed = !isCameraUsed;
	}

	if (isCameraUsed)
	{
		glm::vec2 mousePos = FL::Window::get_mouse_positions();
		glm::vec2 mouse_delta = glm::vec2(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2) - mousePos;
		transform->SetRotation(transform->GetRotation() + glm::vec3(-mouse_delta.y, -mouse_delta.x, 0));
		FL::Window::setCursorPosition(FL::Window::getWidth() / 2, FL::Window::getHeight() / 2);
	}

}
