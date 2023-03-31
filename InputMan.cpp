#include "InputMan.h"

namespace Retro {
	bool InputMan::spriteClick(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect posrect(obj.getPosition().x, obj.getPosition().y, obj.getGlobalBounds().width, obj.getGlobalBounds().height);
			// Checa la posicion del mouse y revisa si se encuentra dentro de un rectángulo que contiene al botón
			if (posrect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}

		}
		return false;
	}
	sf::Vector2i InputMan::getMousePos(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window); // Nos da la posición del mouse relativa a la ventana
	}
};