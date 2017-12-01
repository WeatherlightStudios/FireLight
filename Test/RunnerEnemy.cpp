#include "RunnerEnemy.h"
#include <glm\gtx\vector_angle.inl>
#include <glm\gtc\constants.hpp>

RunnerEnemy::RunnerEnemy(Player* pl)
{
	runner = new Renderable;
	player = pl;
}

void RunnerEnemy::init() {
	this->set_local_scale(glm::vec3(1, 1, 1));
	runner->set_texture("runner");
	runner->set_texture_row(glm::vec2(RUNNER_ROW, RUNNER_COLUMNS));
	runner->set_local_scale(runnerScale);
	this->atuch_children(runner);
}

void RunnerEnemy::update(double dt) {
	//playerPos
	playerPos = player->get_world_position();

	//per vedere se è dentro o fuori dal cerchio basta vedere la distanza dal giocatore
	//se questa è minore di radiusFromPlayer allora runner è troppo vicino, sennò troppo lontano
	//per posizionarsi sul cerchio deve fare una retta da player a runner e spostarsi lungo
	//la retta verso o via dal player

	//posizione runner
	glm::vec3 runnerPos = this->get_local_position();

	glm::vec3 objectiveDir = glm::vec3(0, 0, 0);



	//i due if sono una threshold, quindi il cerchio è diventato un toroide
	//questo imposta l'obbiettivo principale, entrare nel toroide
	if (glm::distance(runnerPos, playerPos) < radiusFromPlayer - radiusThreshold) {
		//enemy è dentro cerchio, quindi allontanati
		//quindi vettore = da player a enemy
		//quindi inverti il vettore
		objectiveDir = runnerPos - playerPos;
	}
	else if (glm::distance(runnerPos, playerPos) > radiusFromPlayer + radiusThreshold) {
		//se enemy è fuori cerchio avvicinati
		//quindi objectivDir è vettore da runner a player
		objectiveDir = playerPos - runnerPos;
	}
	//ora bisogna guardare se si è dentro il toroide e in quel caso correre in senso orario
	if (glm::distance(runnerPos, playerPos) > radiusFromPlayer - radiusThreshold &&
		glm::distance(runnerPos, playerPos) < radiusFromPlayer + radiusThreshold) {


		glm::vec3 circleCenter = playerPos;

		//vettore da player a runner + normalizzazione
		glm::vec3 playerToRunnerDir = runnerPos - playerPos;
		playerToRunnerDir = glm::normalize(playerToRunnerDir);
		//calcolo angolo fra asse x e giocatore
		//se y runner < y player angolo = 2pi - calcolo
		float currentAngle = 0;
		if (runnerPos.y < playerPos.y)
			currentAngle = glm::two_pi<float>() - glm::angle(glm::vec3(1, 0, 0), playerToRunnerDir);
		else
			currentAngle = glm::angle(glm::vec3(1, 0, 0), playerToRunnerDir);
		//aggiungi un po' di angolo
		float newAngle = currentAngle + angleIncrement;
		//calcola quanto andare avanti nel cerchio grazie all'angolo
		glm::vec3 normalyzedPos = glm::vec3(glm::cos(newAngle), glm::sin(newAngle), 0);
		//aumenta lunghezza vettore del raggio attorno al player
		glm::vec3 offset = radiusFromPlayer * normalyzedPos;
		//somma al vettore posizione cerchio per centrarlo, quel punto è dove deve andare il runner
		glm::vec3 whereToGo = circleCenter + offset;
		//obbiettivo = modulo vettore tra runner e dove andare
		objectiveDir = glm::normalize(whereToGo - runnerPos);

	}


	//normalyzation
	objectiveDir.z = 0;
	if (glm::length(objectiveDir) != 0)
		objectiveDir = glm::normalize(objectiveDir);


	glm::vec3 newRunnerPos = runnerPos + objectiveDir * runnerSpeed * (float)dt;
	this->set_local_position(newRunnerPos);

}

void RunnerEnemy::Debug() {

}

RunnerEnemy::~RunnerEnemy()
{

}
