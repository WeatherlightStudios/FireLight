#include "Game.h"

//#include <Windows.h>

#include<iostream>
#include<fstream>
#include<regex>
#include<sstream>
#include<vector>
#include<assert.h>
#include <algorithm>

#include <memory>

std::string vertex;
std::string fragment;

std::vector<std::string> material_parameters;

int main()
{
	std::unique_ptr<Game> newGame = std::make_unique<Game>();
	newGame->Set_DEBUG_MODE();
	newGame->SetWindowDimension(800, 600);
	newGame->SetWindowName("FireLight GameEngine v1.0.0 alpha");
	newGame->Start();

	system("PAUSE");
	return 0;
}