#pragma once

#include "GData.h"
#include "Animator.h"
#include <vector>
namespace Retro {
	/*
		Estado de la splash screen que se muestra al principio del juego
	*/
	class SplashScreen : public State {
	public:
		SplashScreen(GDref data);
		void _init();
		void _inputManager();
		void _update(float deltaTime);
		void _draw(float deltaTime);
	private:
		GDref _data;
		Animator* animator;
		sf::Clock _clock;
		sf::Sprite _bg;
		sf::Sprite _dino;
		std::vector<sf::Texture> texturevec;
	};
};