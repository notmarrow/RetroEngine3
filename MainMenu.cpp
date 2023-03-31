#include "MainMenu.h"
#include "DEF.h"
#include <sstream>
#include "MainGame.h"

namespace Retro {
	MainMenu::MainMenu(GDref data) : _data(data) {}
	void MainMenu::_init() {
		this->_data->Asset.TextureLoad("mainbackground", MAIN_BACKGROUND_PATH);
		this->_data->Asset.TextureLoad("playbutton",NEW_GAME_PATH);
		this->_data->Asset.TextureLoad("quitbutton", QUIT_PATH);

		_bg.setTexture(this->_data->Asset.getTexture("mainbackground"));
		_playbutton.setTexture(this->_data->Asset.getTexture("playbutton"));
		_quitbutton.setTexture(this->_data->Asset.getTexture("quitbutton"));
		// Se cargan las texturas al mapa y luego se asignan a los sprites

		_playbutton.setPosition((SCREEN_WIDTH / 2) - (_playbutton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playbutton.getGlobalBounds().height / 2));
		_quitbutton.setPosition((SCREEN_WIDTH / 2) - (_quitbutton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) + (_quitbutton.getGlobalBounds().height / 2) + (_playbutton.getGlobalBounds().height / 2) - 60);
		// Se posicionan en el menú
	}

	void MainMenu::_inputManager() {
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
			if (_data->Input.spriteClick(_playbutton, sf::Mouse::Left, _data->window)) {
				this->_data->statemachine.Addsref(sref(new MainGame(_data)), true); 
				// Al presionar en el botón de juego se cambia al estado de juego
			}
			if (_data->Input.spriteClick(_quitbutton, sf::Mouse::Left, _data->window)) {
				this->_data->window.close();
				// Al presionar en el botón de salir se sale del juego
			}
		}
	}

	void MainMenu::_update(float deltaTime) {
		
	}

	void MainMenu::_draw(float deltaTime) {
		this->_data->window.clear(sf::Color::Blue);
		this->_data->window.draw(this->_bg);
		this->_data->window.draw(this->_playbutton);
		this->_data->window.draw(this->_quitbutton);
		this->_data->window.display();
	}
};