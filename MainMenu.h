#pragma once
#include "GData.h"
namespace Retro {
	class MainMenu : public State {
	public:
		MainMenu(GDref data);
		void _init();
		void _inputManager();
		void _update(float deltaTime);
		void _draw(float deltaTime);
	private:
		GDref _data;
		sf::Sprite _bg;
		sf::Sprite _playbutton;
		sf::Sprite _quitbutton;
	};
};