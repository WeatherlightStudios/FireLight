#ifndef PLAYER_H
#define PLAYER_H

#include <FireLight.h>

class Player : public SceneNode
{
public:
	Player();
	void init();
	void update(double dt);
	~Player();
private:
	Renderable *m_player;
};

#endif

