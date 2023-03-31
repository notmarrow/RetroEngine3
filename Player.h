#pragma once

#include "appincludes.h"
#include "Game.h"

namespace Retro {
	class Player {
	public:
		Player(GDref data);
		void _draw();
		void anim(float deltaTime);
		void _update(float deltaTime);
		void jump();
		const sf::Sprite& getSprite() const { return playerSprite; }
	private:
		GDref _data;
		sf::Sprite playerSprite;
		std::vector<sf::Texture> animFrames;
		unsigned int animIterator;
		sf::Clock animClock;
		sf::Clock jumpClock;
		int dinoState;
	};

};