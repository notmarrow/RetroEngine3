#pragma once
#include "appincludes.h"

namespace Retro {
	/*
		La clase input manager se encarga de manejar la interacción entre el usuario y el programa
	*/
	class InputMan {
	public: 
		InputMan(){}
		~InputMan(){}
		
		bool spriteClick(sf::Sprite obj, sf::Mouse::Button button, sf::RenderWindow &window);
		sf::Vector2i getMousePos(sf::RenderWindow& window);
	};
};

