#include "Game.h"
#include <toml11/toml.hpp>

void Game::Init()
{
	BG_COLOR(33,161,230);
	SceneManager::AddScene(std::make_unique<Test_Scene>(), "test");
	SceneManager::changeCurrentSceneTo("test");
}
