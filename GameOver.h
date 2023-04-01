#pragma once
#include "GData.h"
namespace Retro {
	/*
		La clase GameOver es un estado que se utiliza cuando el jugador pierde y el juego termina
	*/
	class GameOver : public State {
	public:
		GameOver(GDref data, int score);
		void _init();
		void _inputManager();
		void _update(float deltaTime);
		void _draw(float deltaTime);
	private:
		GDref _data;
		sf::Sprite _bg;
		sf::Sprite _menu;

		sf::Text scoreText;
		sf::Text highScoreText;
		int score;
		int highScore;
	};
};