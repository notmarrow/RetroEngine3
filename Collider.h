#pragma once
#include "appincludes.h"
namespace Retro {
	/*
		La clase collider se encarga de checar las colisiones entre dos objetos
	*/
	class Collider {
	public:
		Collider();
		bool checkCollision(sf::Sprite s1, float  scale1, sf::Sprite s2, float scale2);
	};
};

