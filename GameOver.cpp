#include "GameOver.h"
#include "MainMenu.h"
#include <fstream>
namespace Retro {
	GameOver::GameOver(GDref data, int _score) : _data(data), score(_score) {}
	void GameOver::_init() {
		std::ifstream readFile;
		readFile.open(HIGH_SCORE_FILEPATH);
		highScore = -1; // Se inicia highScore a -1 para prevenir errores de lectura

		if (readFile.is_open()) {
			while (!readFile.eof()) {
				readFile >> highScore;
			}
		} // Se lee la puntuación más alta obtenida que se guarda en un archivo de texto

		readFile.close();

		std::ofstream writeFile(HIGH_SCORE_FILEPATH);
		if (writeFile.is_open()) {
			if (score > highScore) {
				highScore = score;
			} // Si la puntuación actual es más alta que la máxima que estaba guardada antes se asigna como la nueva puntuación máxima

			writeFile << highScore; // Se escribe de nuevo la puntuación máxima en el archivo de texto
		}
		writeFile.close();

		this->_data->Asset.TextureLoad("menu", MENU_PATH);

		_bg.setTexture(this->_data->Asset.getTexture("mainbackground"));
		_menu.setTexture(this->_data->Asset.getTexture("menu"));

		_menu.setPosition((SCREEN_WIDTH / 2) - (_menu.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_menu.getGlobalBounds().height / 2));
		
		// Las siguientes lineas ajustan la configuración de los textos que muestran la puntuación
		scoreText.setFont(_data->Asset.getFont("mainfont"));
		scoreText.setString("Score: " + std::to_string(score));
		scoreText.setCharacterSize(68);
		scoreText.setFillColor(sf::Color::Black);
		scoreText.setOrigin(0, scoreText.getGlobalBounds().height / 2);
		scoreText.setPosition(50, _data->window.getSize().y / 9);

		// Las siguientes lineas ajustan la configuración de los textos que muestran la puntuación máxima
		highScoreText.setFont(_data->Asset.getFont("mainfont"));
		highScoreText.setString("High Score: " + std::to_string(highScore));
		highScoreText.setCharacterSize(68);
		highScoreText.setFillColor(sf::Color::Black);
		highScoreText.setOrigin(0, highScoreText.getGlobalBounds().height / 2);
		highScoreText.setPosition(50, _data->window.getSize().y / 4);
	
	}

	void GameOver::_inputManager() {
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
			if (_data->Input.spriteClick(_menu, sf::Mouse::Left, _data->window)) {
				this->_data->statemachine.Addsref(sref(new MainMenu(_data)), true); // Si se hace click al botón se regresa al menú
			}
		}
	}

	void GameOver::_update(float deltaTime) {

	}

	void GameOver::_draw(float deltaTime) {
		this->_data->window.clear(sf::Color::Blue);
		this->_data->window.draw(this->_bg);
		this->_data->window.draw(this->_menu);
		this->_data->window.draw(this->scoreText);
		this->_data->window.draw(this->highScoreText);
		this->_data->window.display();
	}
};