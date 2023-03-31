#pragma once
#include "appincludes.h"
#include "SplashScreen.h"
#include "GData.h"

namespace Retro {

	class Game {
	public:
		Game(int width, int height, std::string title);
	private: 
		const float deltaTime = 1.0f / 60.0f;
		sf::Clock _clock;
		GDref _data = std::make_shared<GData>();
		void run();
	};

};

