#include "GameScene.h"

GameScene::GameScene()
{

}



void GameScene::Init()
{
	//auto Sprites = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "shader");
	//auto Sprite_test = Resource::LoadTexture("Resources/Sprites/Sprites.png", true, "sprite");
	//auto Sprite_test2 = Resource::LoadTexture("Resources/Sprites/Front.png", true, "sop");

	World::addGameSystem(new FPSCamera());


	camera = World::CreateEntity();
	camera->add_Component<Camera3D>(60.0f);
	camera->add_Component<Transform>(glm::vec3(0,0,0), glm::vec3(0,0,0), glm::vec3(0,0,0));

}



void GameScene::Update()
{

}

glm::vec3 GameScene::projectOnPlane(glm::vec3 point, glm::vec3 norm) {
	auto dist = point.x * norm.x + point.y * norm.y + point.z * norm.z;
	return point - dist * norm;
}

float GameScene::angleBetween(glm::vec2 A, glm::vec2 B) {
	auto normA = glm::normalize(A);
	auto normB = glm::normalize(B);
	return glm::acos(glm::dot(normA, normB));
}

void GameScene::Debug()
{
	auto cam = camera->get_Component<Camera3D>();
	AxisGizmo(cam);
	CamGizmo(cam);
}

// Camera Control Settins
void GameScene::CamGizmo(Camera3D* cam) {
	ImGui::Begin("Camera Control Settings", NULL, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.45f);

	ImGui::DragFloat("Camera Speed", &cam->velocity, 0.005f);
	ImGui::InputFloat("Speed Multiplier", &cam->speedMultiplier);
	ImGui::SliderFloat("Mouse Sensitivity", &cam->rotVelocity, 0.005f, 2.0f);
	ImGui::DragFloat2("Clip Planes Distances", cam->planeDist, 0.001f, 0.0f, 10000000.0f);

	ImGui::End();
}

// Gizmo degli assi del mondo:
// In alto a destra c'è una finestra che mostra i 3 assi del mondo e dove sono orientati.
void GameScene::AxisGizmo(Camera3D* cam) {

	auto projz = projectOnPlane(cam->forward, glm::vec3(0, 0, 1));
	auto projx = projectOnPlane(cam->left, glm::vec3(0, 0, 1));
	auto projy = projectOnPlane(-cam->upward, glm::vec3(0, 0, 1));

	const uint32_t WIN_SIZE = 210;
	const uint32_t WIN_BORDER = 20;
	ImGui::SetNextWindowSize(ImVec2(WIN_SIZE, WIN_SIZE));
	ImGui::SetNextWindowPos(ImVec2(FL::Window::getWidth() - WIN_BORDER - WIN_SIZE, WIN_BORDER));
	ImGui::Begin("Axis Gizmo", NULL, ImGuiWindowFlags_NoResize);

	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	static ImColor colx = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
	static ImColor coly = ImColor(0.0f, 1.0f, 0.0f, 1.0f);
	static ImColor colz = ImColor(0.0f, 0.0f, 1.0f, 1.0f);
	//TODO: remove x and y and GetCursorScreenPos (if possible)
	const ImVec2 p = ImGui::GetCursorScreenPos();
	float x = p.x + 4.0f;
	float y = p.y + 4.0f;

	float lineWidth = 2.0f;
	float lineLength = 50;
	float centerSpacer = 90;

	auto centerPos = ImVec2(x + centerSpacer, y + centerSpacer);

	auto zPos = ImVec2(centerPos.x + projz.x * lineLength, centerPos.y + projz.y * lineLength);
	auto xPos = ImVec2(centerPos.x + projx.x * lineLength, centerPos.y + projx.y * lineLength);
	auto yPos = ImVec2(centerPos.x + projy.x * lineLength, centerPos.y + projy.y * lineLength);
	//draw main lines
	draw_list->AddLine(centerPos, zPos, colz, lineWidth);
	draw_list->AddLine(centerPos, xPos, colx, lineWidth);
	draw_list->AddLine(centerPos, yPos, coly, lineWidth);

	//calculate and draw arrows tips
	auto right = glm::vec2(100, 0);
	float angleCone = glm::radians(10.0f);
	float distanceExtra = 10.0f;


	auto newX = glm::vec2(xPos.x, xPos.y) - glm::vec2(centerPos.x, centerPos.y);
	auto angleX = angleBetween(newX, right);
	auto lengthX = glm::length(newX);
	auto pointAX = polarToEuclidian(lengthX, angleX + angleCone);
	auto pointCX = polarToEuclidian(lengthX, angleX - angleCone);
	auto pointLinedX = ImVec2(centerPos.x + projx.x * (lineLength + distanceExtra), centerPos.y + projx.y * (lineLength + distanceExtra));

	auto newY = glm::vec2(yPos.x, yPos.y) - glm::vec2(centerPos.x, centerPos.y);
	auto angleY = angleBetween(newY, right);
	if (newY.y < 0) angleY *= -1;
	auto lengthY = glm::length(newY);
	auto pointAY = polarToEuclidian(lengthY, angleY + angleCone);
	auto pointCY = polarToEuclidian(lengthY, angleY - angleCone);
	auto pointLinedY = ImVec2(centerPos.x + projy.x * (lineLength + distanceExtra), centerPos.y + projy.y * (lineLength + distanceExtra));

	auto newZ = glm::vec2(zPos.x, zPos.y) - glm::vec2(centerPos.x, centerPos.y);
	auto angleZ = angleBetween(newZ, right);
	if (newZ.y < 0) angleZ *= -1;
	auto lengthZ = glm::length(newZ);
	auto pointAZ = polarToEuclidian(lengthZ, angleZ + angleCone);
	auto pointCZ = polarToEuclidian(lengthZ, angleZ - angleCone);
	auto pointLinedZ = ImVec2(centerPos.x + projz.x * (lineLength + distanceExtra), centerPos.y + projz.y * (lineLength + distanceExtra));

	draw_list->AddLine(ImVec2(centerPos.x + pointAX.x, centerPos.y + pointAX.y), pointLinedX, colx, lineWidth);
	draw_list->AddLine(pointLinedX, ImVec2(centerPos.x + pointCX.x, centerPos.y + pointCX.y), colx, lineWidth);

	draw_list->AddLine(ImVec2(centerPos.x + pointAY.x, centerPos.y + pointAY.y), pointLinedY, coly, lineWidth);
	draw_list->AddLine(pointLinedY, ImVec2(centerPos.x + pointCY.x, centerPos.y + pointCY.y), coly, lineWidth);

	draw_list->AddLine(ImVec2(centerPos.x + pointAZ.x, centerPos.y + pointAZ.y), pointLinedZ, colz, lineWidth);
	draw_list->AddLine(pointLinedZ, ImVec2(centerPos.x + pointCZ.x, centerPos.y + pointCZ.y), colz, lineWidth);

	ImGui::End();
}

glm::vec2 GameScene::polarToEuclidian(float length, float angle) {
	return glm::vec2(length * glm::cos(angle), length * glm::sin(angle));
}

void GameScene::Close()
{

}


GameScene::~GameScene()
{

}