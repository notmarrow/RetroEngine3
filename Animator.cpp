#include "Animator.h"
namespace Retro {
	Animator::Animator(std::vector<sf::Texture> spritevec): 
		animFrames(spritevec)
	{
		animIterator = 0;
		currentSprite  = animFrames.at(animIterator);
	}

	void Animator::animate(float _speed) {
		if (animClock.getElapsedTime().asSeconds() > _speed / animFrames.size()) {
			if (animIterator < animFrames.size() - 1) {
				animIterator++; // Pasa al siguiente frame si aun quedan frames en el vector de frames
			}
			else {
				animIterator = 0; // Regresa al primer frame si ya se uso el último
			}
			currentSprite = animFrames.at(animIterator);
			animClock.restart();
		}
	}
	/*
		El método animate usa un reloj para iterar a traves de un vector de frames de la animación a una cierta velocidad
		en segundos, regresa el sprite del frame actual para asignarse al sprite del objeto animado para dibujarse
	*/
};