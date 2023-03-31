#pragma once
#include "GData.h"
#include "Obstacle.h"
#include "Player.h"
#include "Collider.h"
#include "ScoreHud.h"
namespace Retro {
	class MainGame : public State {
	public:
		MainGame(GDref data);
		void _init();
		void _inputManager();
		void _update(float deltaTime);
		void _draw(float deltaTime);
	private:
		GDref _data;
		sf::Sprite _bg;
		sf::Sprite _home;

		Obstacle* obstacles;
		Player* dino;
		sf::Clock _clockcactus;
		sf::Clock _clockbird;
		Collider collider;
		ScoreHud* scorehud;
		int gameState;
		int score;
	};
};