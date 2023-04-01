#pragma once
#include "GData.h"
#include "Obstacle.h"
#include "Player.h"
#include "Collider.h"
#include "ScoreHud.h"
namespace Retro {
	/*
		MainGame es el estado principal del juego, el cual contiene el loop principal del juego que se encarga de mover los
		obstáculos, registrar colisiones y controlar la puntuación
	*/
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
		sf::Clock _clockbird; // Se usan dos relojes para controlar el spawn de los diferentes obstáculos
		Collider collider;
		ScoreHud* scorehud;
		int gameState; // gameState se usa para registrar si el jugador esta jugando o si el juego ha terminado
		int score;

		sf::SoundBuffer pointSoundBuffer;
		sf::Sound pointSound;
	};
};