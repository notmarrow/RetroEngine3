#include "Game.h"

namespace Retro {
	Game::Game(int width, int height, std::string title) {
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		// Se crea la ventana principal
		_data->statemachine.Addsref(sref(new SplashScreen(this->_data)));
		// Se añade el estado de SplashScreen a la máquina de estados
		this->run();
	}
	void Game::run() {
		float newt, framet, interpol; // Variables para el cálculo de deltaTime
		float currentt = this->_clock.getElapsedTime().asSeconds(); // Se toma el tiempo actual
		float accumulator = 0.0f; // Variable para acumular la diferencia de tiempo con el deltaTime
		while (this->_data->window.isOpen()) {
			this->_data->statemachine.ProcesssrefChange(); // Se procesa cualquier cambio de estado
			newt = this->_clock.getElapsedTime().asSeconds(); // Tiempo despues de procesar el cambio de estado
			framet = newt - currentt; // Tiempo de frame se calcula restando al tiempo de proceso el tiempo de inicio
			if (framet > 0.25f) {
				framet = 0.25f; // Se usa para limitar el tiempo de frame
			}
			currentt = newt; // Se actualiza el tiempo de inicio
			accumulator += framet; // Se añade el tiempo de frame al acumulador
			while (accumulator >= deltaTime) {
				this->_data->statemachine.GetCurrentState()->_inputManager(); 
				this->_data->statemachine.GetCurrentState()->_update(deltaTime); 
				// Se usa para actualizar el estado siempre y cuando tengamos tiempo acumulado más allá de nuestro deltaTime
				accumulator -= deltaTime; // Se resta al acumulador nuestro deltaTime
			}
			interpol = accumulator / deltaTime; 
			/* 
				Se usa para calcular la interpolación(la diferencia entre la posición y el movimiento de los objetos según
				la cantidad de tiempo que ha pasado desde la última actualización). interpol es una relación entre la 
				acumulación de tiempo desde la ultima actualización y el deltaTime.
			*/
			this->_data->statemachine.GetCurrentState()->_draw(interpol);
		}
	}
};