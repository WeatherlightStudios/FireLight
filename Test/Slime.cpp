#include "Slime.h"



Slime::Slime(DataCenter* cntr) {
	slime = new Renderable;
	dataCenter = cntr;
}



void Slime::init() {
	this->set_local_scale(glm::vec3(1, 1, 1));
	slime->set_texture("slime");
	slime->set_texture_row(glm::vec2(SLIME_ROW, SLIME_COLUMNS));
	slime->set_local_scale(glm::vec3(0.35, 0.35, 0.35));
	this->atuch_children(slime);
	
	//slime setup
	slimeChangingSpeed = slimeSpeed;
	//slime anim setup
	slimeXAnim = SLIME_IDLE;
	slimeYAnim = SLIME_ANIM_Y;

}

void Slime::Debug() {

}


void Slime::update(double dt) {
	///SLIME///
	
	//slime pos
	glm::vec3 slimePos = slime->get_world_position();
	
	//slime ha bisogno della posizione del player quindi slime si prende da dataCenter playerPos,
	//mentre player ci mette playerPos
	playerPos = dataCenter->getVector3("PlayerPos");


	//constantemente diminuisce la velocità dello slime
	slimeChangingSpeed -= speedDecrease * dt;

	//se la velocità dello slime è sotto lo zero fa partire il timer e blocca il valore
	//altrimenti resetta timer
	if (slimeChangingSpeed > 0) {
		timer = slimeLaunchTimer;
	}
	else {
		slimeChangingSpeed = 0;
		timer -= dt;
	}

	//quando timer è sotto a 0 fa uno scatto, quindi resetta la velocità dello slime
	if (timer <= 0) {

		//direzione da slime a giocatore
		slimeToPlayerDir = playerPos - slimePos;

		//ignora asse z
		slimeToPlayerDir.z = 0;
		//proiezione sul piano con modulo 1 (se tutti diversi da 0)
		if (glm::length(slimeToPlayerDir) != 0)
			slimeToPlayerDir = glm::normalize(slimeToPlayerDir);


		slimeChangingSpeed = slimeSpeed;
	}

	//aggiornamento posizione slime
	glm::vec3 newSlimePos = slimePos + slimeToPlayerDir * slimeChangingSpeed * (float)dt;
	slime->set_local_position(newSlimePos);

	//aggiornamento animazione slime
	slime->set_texture_offset(glm::vec2(slimeXAnim, slimeYAnim));
	//UpdateAnim(slimeXAnim, slimeYAnim);

}

//USELESS
void Slime::UpdateAnim(int texX, int texY) {
	slime->set_texture_offset(glm::vec2(texX, texY));
}


Slime::~Slime()
{
}
