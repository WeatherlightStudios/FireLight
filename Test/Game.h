#pragma once

#include <FireLight.h>


class Game : public FL::App
{
public:
	Game();

	void Init();
	void Update(double deltaT);
	void Draw();
	void Close();

	~Game();
private:


};

