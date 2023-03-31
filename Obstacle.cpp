#include "Obstacle.h"

namespace Retro {
	Obstacle::Obstacle(GDref data) : _data(data){}
	void Obstacle::_draw() {
		for (unsigned short int i = 0; i < obsspritevec.size(); i++) {
			_data->window.draw(obsspritevec[i]);
		}
	}

	void Obstacle::spawncactus() {
		sf::Sprite sprite(_data->Asset.getTexture("cactuss"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - 10);
		obsspritevec.push_back(sprite);
	}

	void Obstacle::spawnbird() {
		sf::Sprite sprite(_data->Asset.getTexture("bird"));
		sprite.setPosition(_data->window.getSize().x, 50);
		obsspritevec.push_back(sprite);
	}

	void Obstacle::spawnScoreCheck() {
		sf::Sprite sprite(this->_data->Asset.getTexture("cactusl"));
		sprite.setPosition(_data->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));
		scorevec.push_back(sprite);
	}

	void Obstacle::_move(float deltaTime) {
		for (unsigned short int i = 0; i < obsspritevec.size(); i++) {
			if (obsspritevec.at(i).getPosition().x < 0 - obsspritevec.at(i).getGlobalBounds().width) {
				obsspritevec.erase(obsspritevec.begin() + i);
			}
			else {
				float movement = OBSTACLE_SPEED * deltaTime;
				obsspritevec.at(i).move(-movement, 0);
			}
		}
		for (unsigned short int i = 0; i < scorevec.size(); i++) {
			if (scorevec.at(i).getPosition().x < 0 - scorevec.at(i).getGlobalBounds().width) {
				scorevec.erase(scorevec.begin() + i);
			}
			else {
				float movement = OBSTACLE_SPEED * deltaTime;
				scorevec.at(i).move(-movement, 0);
			}
		}
	}
};