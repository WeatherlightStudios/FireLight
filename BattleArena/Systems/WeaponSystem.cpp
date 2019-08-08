#include "WeaponSystem.h"
#include <glm/gtx/rotate_vector.hpp>
#include <glm/glm.hpp>
#include <math.h>
#include <string>


WeaponSystem::WeaponSystem(EntityHandler* camera, EntityHandler* player)
{
	m_camera = camera;
	m_player = player;

	registerComponent(Weapon::ID);
}


void WeaponSystem::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	Weapon* weapon = World::getComponent<Weapon>(entity);

	//transform->Rotation = -1.57;
	glm::vec2 mousePos = FL::Window::get_mouse_positions();

	glm::vec4 viewport = glm::vec4(0.0f, 0.0f, FL::Window::getWidth(), FL::Window::getHeight());
	glm::vec3 worldMousePos = glm::unProject(glm::vec3(mousePos.x, mousePos.y, 0.0f), glm::mat4(1.0f), m_camera->get_Component<Camera2D>()->projection, viewport);

	glm::vec2 newPos = worldMousePos - glm::vec3(m_player->get_Component<Transform>()->Position.x, -m_player->get_Component<Transform>()->Position.y, 0.0f);

	float angle = atan2(-newPos.x, -newPos.y);

	weapon->angle = angle;
	transform->Rotation = angle;

	//glm::vec2 mousePos(W)

	//glm::vec2 rot = glm::rotate(glm::vec2(25.0f, 25.0f), angle);

	transform->Position = m_player->get_Component<Transform>()->Position + glm::normalize(glm::vec2(newPos.x, -newPos.y)) * glm::vec2(50,50);



}

WeaponSystem::~WeaponSystem()
{
}
