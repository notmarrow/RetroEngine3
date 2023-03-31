#pragma once
#include "appincludes.h"
#include "GData.h"
namespace Retro {
	/*
		Anima un sprite usando un vector de texturas, regresa como resultado una textura actual la cual se puede
		asignar a un sprite para ser dibujada en los métodos de renderizado
	*/
	class Animator {
	public:
		Animator(std::vector<sf::Texture> spritevec);
		void animate(float _speed);
		sf::Texture& getCurrentSprite() { return currentSprite; }
	private:
		std::vector<sf::Texture> animFrames;
		unsigned int animIterator;
		sf::Clock animClock;
		sf::Texture currentSprite;
	};
};
