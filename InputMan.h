#pragma once
#include "appincludes.h"

namespace Retro {
	class InputMan {
	public: 
		InputMan(){}
		~InputMan(){}
		
		bool spriteClick(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow &window);
		sf::Vector2i getMousePos(sf::RenderWindow& window);
	};
};

