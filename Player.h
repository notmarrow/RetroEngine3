#pragma once

#include "appincludes.h"
#include "Game.h"

namespace Retro {
	/*
		La clase Player se encarga de manejar las cuestiones relacionadas al jugador principal, como mantener registro de
		el estado del jugador (si esta saltando, cayendo o quieto) as� como actuar en base al input del usuario y manejar su
		animaci�n
	*/
	class Player {
	public:
		Player(GDref data);
		void _draw();
		void anim(float deltaTime); // Este es un m�todo de animaci�n por lo que Player no usa la clase Animator
		void _update(float deltaTime);
		void jump();
		const sf::Sprite& getSprite() const { return playerSprite; }
	private:
		GDref _data;
		sf::Sprite playerSprite;
		std::vector<sf::Texture> animFrames; // Vector con los frames de la animaci�n
		unsigned int animIterator; // Iterador para el vector de frames
		sf::Clock animClock;
		sf::Clock jumpClock;
		int dinoState; // Entero que nos ayudar� a registrar el estado del jugador (si esta saltando, cayendo o quieto)
	};

};