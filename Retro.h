#pragma once

namespace Retro {
	/*
		La clase state es una clase virtual pura de la cual heredan los diferentes estados del juego
	*/
	class State {
	public:
		virtual void _init() = 0;
		virtual void _inputManager() = 0;
		virtual void _update(float deltaTime) = 0;
		virtual void _draw(float deltaTime) = 0;
		virtual void _pause(){}
		virtual void _unpause(){}
	};
};