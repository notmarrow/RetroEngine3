#pragma once

namespace Retro {
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