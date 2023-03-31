#include "Game.h"

namespace Retro {
	Game::Game(int width, int height, std::string title) {
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->statemachine.Addsref(sref(new SplashScreen(this->_data)));
		this->run();
	}
	void Game::run() {
		float newt, framet, interpol;
		float currentt = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;
		while (this->_data->window.isOpen()) {
			this->_data->statemachine.ProcesssrefChange();
			newt = this->_clock.getElapsedTime().asSeconds();
			framet = newt - currentt;
			if (framet > 0.25f) {
				framet = 0.25f;
			}
			currentt = newt;
			accumulator += framet;
			while (accumulator >= deltaTime) {
				this->_data->statemachine.GetCurrentState()->_inputManager();
				this->_data->statemachine.GetCurrentState()->_update(deltaTime);
				accumulator -= deltaTime;
			}
			interpol = accumulator / deltaTime;
			this->_data->statemachine.GetCurrentState()->_draw(interpol);
		}
	}
};