#include "Game.h"

namespace Retro {
	Game::Game(int width, int height, std::string title) {
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		// Se crea la ventana principal
		_data->statemachine.Addsref(sref(new SplashScreen(this->_data)));
		// Se a�ade el estado de SplashScreen a la m�quina de estados
		this->run();
	}
	void Game::run() {
		float newt, framet, interpol; // Variables para el c�lculo de deltaTime
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
			accumulator += framet; // Se a�ade el tiempo de frame al acumulador
			while (accumulator >= deltaTime) {
				this->_data->statemachine.GetCurrentState()->_inputManager(); 
				this->_data->statemachine.GetCurrentState()->_update(deltaTime); 
				// Se usa para actualizar el estado siempre y cuando tengamos tiempo acumulado m�s all� de nuestro deltaTime
				accumulator -= deltaTime; // Se resta al acumulador nuestro deltaTime
			}
			interpol = accumulator / deltaTime; 
			/* 
				Se usa para calcular la interpolaci�n(la diferencia entre la posici�n y el movimiento de los objetos seg�n
				la cantidad de tiempo que ha pasado desde la �ltima actualizaci�n). interpol es una relaci�n entre la 
				acumulaci�n de tiempo desde la ultima actualizaci�n y el deltaTime.
			*/
			this->_data->statemachine.GetCurrentState()->_draw(interpol);
		}
	}
};