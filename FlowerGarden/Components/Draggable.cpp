#include "Draggable.h"

void Draggable::Init()
{
	FL::LOG_INFO("this gameObject is ", gameObject);
	FL::LOG_ERROR("this Object is ", this);
	homePos = gameObject->GetComponent<Transform>()->GetPosition();
}

void Draggable::Update()
{
	//TODO: refactor with shared_ptr / weak_ptr
	auto transform = gameObject->GetComponent<Transform>();

	glm::vec2 mousePos = FL::Window::get_mouse_positions();
	glm::vec4 viewport = glm::vec4(0.0f, 0.0f, FL::Window::getWidth(), FL::Window::getHeight());

	auto projection = glm::ortho(-800.0f, 800.0f, -600.0f, 600.0f, 0.001f, 1000.0f);
	projection = glm::translate(projection, glm::vec3(0, 0, -3));

	glm::vec3 worldMousePos = glm::unProject(glm::vec3(mousePos.x, viewport[3] - mousePos.y, 0.0f), glm::mat4(1.0f), projection, viewport);

	//std::cout << "world mouse position: (" << worldMousePos.x << ", " << worldMousePos.y << ")" << std::endl;
	//std::cout << "object world position: (" << transform->Position.x << ", " << transform->Position.y <<")" << std::endl;

	//transform->Scale * 8.0f, quel * 8.0f non dovrebbe non essere necessario ?
	if (IsInside(worldMousePos, transform->GetPosition(), transform->GetScale() * 16.0f) && FL::Window::isKeyDown(KEYCODE::KEY_SPACE)) {
		isPicked = true;
		//FL::LOG_INFO("picked an object, value is now ", isPicked, ", home position is: ", homePos);
		//FL::LOG_INFO("this object is ", static_cast<const void*>(this));
		//FL::LOG_INFO("HomePos of this object is: ", homePos);
	}
	else if (FL::Window::isKeyUp(KEYCODE::KEY_SPACE)) {
		isPicked = false;
		FL::LOG_INFO("released an object, value is now ", isPicked);
	}

	if (isPicked) {
		//std::cout << "picking object, value is now " << draggable->isPicked << std::endl;
		transform->SetPosition(worldMousePos);
	}
	else {
		glm::vec2 diff = homePos - transform->GetPosition();
		if (glm::length(diff) >= 1.0f) {
			transform->SetPosition( transform->GetPosition() + diff * returnSpeed * (float)Time::GetDeltaTime());
		}
	}
}

//standard AABB detection
bool Draggable::IsInside(glm::vec2 inputPos, glm::vec2 areaPos, glm::vec2 areaSize) {

	if (inputPos.x > areaPos.x + areaSize.x || inputPos.x < areaPos.x - areaSize.x) {
		return false;
	}

	if (inputPos.y > areaPos.y + areaSize.y || inputPos.y < areaPos.y - areaSize.y) {
		return false;
	}

	//inside the area
	return true;
}
