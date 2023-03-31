#include "Obstacle.h"

namespace Retro {
	Obstacle::Obstacle(GDref data) : _data(data){}
	void Obstacle::_draw() {
		for (unsigned short int i = 0; i < obsspritevec.size(); i++) {
			_data->window.draw(obsspritevec[i]);
		} // Se itera el vector de sprites para dibujarlos
	}

	void Obstacle::spawncactus() {
		sf::Sprite sprite(_data->Asset.getTexture("cactuss"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - 10);
		obsspritevec.push_back(sprite);
	} // Se crea un sprite con la textura de cactus y se posiciona en el extremo de la pantalla, luego se añade al vector

	void Obstacle::spawnbird() {
		sf::Sprite sprite(_data->Asset.getTexture("bird"));
		sprite.setPosition(_data->window.getSize().x, 50);
		obsspritevec.push_back(sprite);
	} // Se crea un sprite con la textura de pájaro y se posiciona en el extremo de la pantalla, luego se añade al vector

	void Obstacle::spawnScoreCheck() {
		sf::Sprite sprite(this->_data->Asset.getTexture("cactusl"));
		sprite.setPosition(_data->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));
		scorevec.push_back(sprite);
	} // Se crea un sprite y se posiciona en el extremo de la pantalla, después se hace invisible y se añade al vector de puntuación

	void Obstacle::_move(float deltaTime) {
		for (unsigned short int i = 0; i < obsspritevec.size(); i++) {
			if (obsspritevec.at(i).getPosition().x < 0 - obsspritevec.at(i).getGlobalBounds().width) {
				obsspritevec.erase(obsspritevec.begin() + i);
			} // Si el sprite sale de la pantalla se elimina
			else {
				float movement = OBSTACLE_SPEED * deltaTime;
				obsspritevec.at(i).move(-movement, 0);
			} // Si no, se mueve según la velocidad de movimiento usando la función integrada en SFML
		}
		for (unsigned short int i = 0; i < scorevec.size(); i++) {
			if (scorevec.at(i).getPosition().x < 0 - scorevec.at(i).getGlobalBounds().width) {
				scorevec.erase(scorevec.begin() + i);
			} // Si el sprite sale de la pantalla se elimina
			else {
				float movement = OBSTACLE_SPEED * deltaTime;
				scorevec.at(i).move(-movement, 0);
			} // Si no, se mueve según la velocidad de movimiento usando la función integrada en SFML
		}
	}
};