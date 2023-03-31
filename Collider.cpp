#include "Collider.h"

namespace Retro {
	Collider::Collider(){}
	bool Collider::checkCollision(sf::Sprite s1, float  scale1, sf::Sprite s2, float scale2) {
		s1.setScale(scale1, scale2);
		s2.setScale(scale1, scale2); // Se permite cambiar la escala para ajustar el collider en caso de que sea demasiado grande
		sf::Rect<float> rect1 = s1.getGlobalBounds();
		sf::Rect<float> rect2 = s2.getGlobalBounds(); // Se guardan las posiciones del contorno del sprite
		if (rect1.intersects(rect2)) { // Se checa si el objeto 1 intersecta al objeto 2
			return true;
		}
		else
		{
			return false;
		}
	}
};