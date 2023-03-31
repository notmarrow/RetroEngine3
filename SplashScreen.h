#pragma once

#include "GData.h"
namespace Retro {
	class SplashScreen : public State {
	public:
		SplashScreen(GDref data);
		void _init();
		void _inputManager();
		void _update(float deltaTime);
		void _draw(float deltaTime);
	private:
		GDref _data;
		sf::Clock _clock;
		sf::Sprite _bg;
		sf::Sprite _dino;
	};
};