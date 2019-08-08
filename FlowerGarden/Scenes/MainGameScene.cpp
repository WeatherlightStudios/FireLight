#include "MainGameScene.h"

MainGameScene::MainGameScene() {

}

void MainGameScene::Init() {
	auto sheet_transp = Resource::LoadTexture("Resources/Sprites/Sprites_Transparent.png", true, "sheet_transp");
	auto sheet_black  = Resource::LoadTexture("Resources/Sprites/Sprites_BlackBG.png",    false, "sheet_black");
	auto shader = Resource::LoadShader("Resources/Shaders/2D_shader.vert", "Resources/Shaders/2D_shader.frag", NULL, "2D_shader");

}

void MainGameScene::Update() {

}

void MainGameScene::Debug() {

}

void MainGameScene::Close(){

}

MainGameScene::~MainGameScene(){

}