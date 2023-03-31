#pragma once
#include "appincludes.h"
#include "GData.h"
namespace Retro {
	/*
		La clase Obstacle se encarga de manejar los obstáculos que el jugador tendrá que esquivar
	*/
	class Obstacle {
	public:
		Obstacle(GDref data);
		void _draw();
		void spawncactus();
		void spawnbird();
		void spawnScoreCheck(); // Un obstáculo con el que se hace collide pero que en lugar de acabar el juego suma puntuación
		void _move(float deltaTime); // Mueve los obstáculos
		const std::vector<sf::Sprite>& getSpriteVect() const { return obsspritevec; } // Un vector que contiene los obstáculos
		std::vector<sf::Sprite>& getScoreVect() { return scorevec; } // Un vector que contiene los colliders de puntuación
	private:
		GDref _data;
		std::vector<sf::Texture> birdSprites;
		std::vector<sf::Sprite> obsspritevec;
		std::vector<sf::Sprite> scorevec;
	};
};

