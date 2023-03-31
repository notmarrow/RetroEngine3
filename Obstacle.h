#pragma once
#include "appincludes.h"
#include "GData.h"
namespace Retro {
	/*
		La clase Obstacle se encarga de manejar los obst�culos que el jugador tendr� que esquivar
	*/
	class Obstacle {
	public:
		Obstacle(GDref data);
		void _draw();
		void spawncactus();
		void spawnbird();
		void spawnScoreCheck(); // Un obst�culo con el que se hace collide pero que en lugar de acabar el juego suma puntuaci�n
		void _move(float deltaTime); // Mueve los obst�culos
		const std::vector<sf::Sprite>& getSpriteVect() const { return obsspritevec; } // Un vector que contiene los obst�culos
		std::vector<sf::Sprite>& getScoreVect() { return scorevec; } // Un vector que contiene los colliders de puntuaci�n
	private:
		GDref _data;
		std::vector<sf::Texture> birdSprites;
		std::vector<sf::Sprite> obsspritevec;
		std::vector<sf::Sprite> scorevec;
	};
};

