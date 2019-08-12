#include "Draggable_S.h"
#include <iostream>

Draggable_S::Draggable_S(EntityHandler* camera):
	cam(camera)
{
	registerComponent(Transform::ID);
	registerComponent(Draggable::ID);
}

void Draggable_S::Update(uint32_t entity) {
	//TODO: refactor with shared_ptr / weak_ptr
	Transform* transform = World::getComponent<Transform>(entity);
	Draggable* draggable = World::getComponent<Draggable>(entity);


	glm::vec2 mousePos = FL::Window::get_mouse_positions();
	glm::vec4 viewport = glm::vec4(0.0f, 0.0f, FL::Window::getWidth(), FL::Window::getHeight());
	glm::vec3 worldMousePos = glm::unProject(glm::vec3(mousePos.x,viewport[3]- mousePos.y, 0.0f), glm::mat4(1.0f), cam->get_Component<Camera2D>()->projection, viewport);

	//std::cout << "world mouse position: (" << worldMousePos.x << ", " << worldMousePos.y << ")" << std::endl;
	//std::cout << "object world position: (" << transform->Position.x << ", " << transform->Position.y <<")" << std::endl;

	//transform->Scale * 8.0f, quel * 8.0f non dovrebbe non essere necessario ?
	if (IsInside(worldMousePos, transform->Position, transform->Scale * 8.0f) && FL::Window::isKeyDown(KEYCODE::KEY_SPACE)) {
		draggable->isPicked = true;
		std::cout << "picked an object, value is now " << draggable->isPicked << std::endl;
	}
	else if (FL::Window::isKeyUp(KEYCODE::KEY_SPACE)) {
		draggable->isPicked = false;
		std::cout << "released an object, value is now " << draggable->isPicked <<  std::endl;
	}

	if (draggable->isPicked) {
		//std::cout << "picking object, value is now " << draggable->isPicked << std::endl;
		transform->Position = worldMousePos;
	}
	else {
		glm::vec2 diff = draggable->homePos - transform->Position;
		if (glm::length(diff) >= 1.0f) {
			transform->Position += diff * draggable->returnSpeed * (float)Time::GetDeltaTime();
		}
	}

	//std::cout << "object " << draggable->name << " has value " << draggable->isPicked << std::endl;

}

//standard AABB detection
bool Draggable_S::IsInside(glm::vec2 inputPos, glm::vec2 areaPos, glm::vec2 areaSize) {

	if (inputPos.x > areaPos.x + areaSize.x || inputPos.x < areaPos.x - areaSize.x) {
		return false;
	}

	if (inputPos.y > areaPos.y + areaSize.y || inputPos.y < areaPos.y - areaSize.y) {
		return false;
	}

	//inside the area
	return true;
}

Draggable_S::~Draggable_S() {

}

