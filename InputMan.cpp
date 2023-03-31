#include "InputMan.h"

namespace Retro {
	bool InputMan::spriteClick(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect posrect(obj.getPosition().x, obj.getPosition().y, obj.getGlobalBounds().width, obj.getGlobalBounds().height);
			if (posrect.contains(sf::Mouse::getPosition(window))) {
				return true;
			}

		}
		return false;
	}
	sf::Vector2i InputMan::getMousePos(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window);
	}
};