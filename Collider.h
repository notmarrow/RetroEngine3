#pragma once
#include "appincludes.h"
namespace Retro {
	class Collider {
	public:
		Collider();
		bool checkCollision(sf::Sprite s1, float  scale1, sf::Sprite s2, float scale2);
	};
};

