#pragma once
#include "appincludes.h"

#include "Game.h"

namespace Retro {
	/*
		La clase ScoreHud se usa para dibujar y mantener registro de la puntuación del usuario
	*/
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
