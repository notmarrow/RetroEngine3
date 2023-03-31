#pragma once
#include "appincludes.h"
#include "GData.h"
namespace Retro {
	class Obstacle {
	public:
		Obstacle(GDref data);
		void _draw();
		void spawncactus();
		void spawnbird();
		void spawnScoreCheck();
		void _move(float deltaTime);
		const std::vector<sf::Sprite>& getSpriteVect() const { return obsspritevec; }
		std::vector<sf::Sprite>& getScoreVect() { return scorevec; }
	private:
		GDref _data;
		std::vector<sf::Sprite> obsspritevec;
		std::vector<sf::Sprite> scorevec;
	};
};

