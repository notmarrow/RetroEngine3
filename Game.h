#pragma once
#include "appincludes.h"
#include "SplashScreen.h"
#include "GData.h"

namespace Retro {
	/*
		La clase Game es la clase principal del engine en la que se encuentra el loop principal que maneja los distintos 
		estados
	*/
	class Game {
	public:
		Game(int width, int height, std::string title);
	private: 
		const float deltaTime = 1.0f / 60.0f;
		sf::Clock _clock;
		GDref _data = std::make_shared<GData>(); // Objeto de tipo GData que contiene los elementos más importantes del engine
		void run();
	};

};

