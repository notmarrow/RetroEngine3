#pragma once
#include "appincludes.h"

#include "Game.h"

namespace Retro {
	class ScoreHud
	{
	public: 
		ScoreHud(GDref data);
		void _draw();
		void scoreUpdate(int score);
	private:
		GDref _data;
		sf::Text _scoreT;
	};
};
