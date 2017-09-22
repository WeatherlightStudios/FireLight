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

	double m_mouseX, m_mouseY;
	double OldmouseX, OldmouseY;

	float m_paddleONE_pos_x;
	float m_paddleONE_pos_y;

	float m_paddleTWO_pos_x;
	float m_paddleTWO_pos_y;

	float m_ball_pos_x;
	float m_ball_pos_y;


	Renderable m_paddle1;
	Renderable m_paddle2;
	Renderable m_ball;
	Camera m_camera;
};

