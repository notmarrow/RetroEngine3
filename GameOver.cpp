#include "GameOver.h"
#include "MainMenu.h"
namespace Retro {
	GameOver::GameOver(GDref data) : _data(data) {}
	void GameOver::_init() {
		this->_data->Asset.TextureLoad("menu", MENU_PATH);

		_bg.setTexture(this->_data->Asset.getTexture("mainbackground"));
		_menu.setTexture(this->_data->Asset.getTexture("menu"));

		_menu.setPosition((SCREEN_WIDTH / 2) - (_menu.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_menu.getGlobalBounds().height / 2));
	}

	void GameOver::_inputManager() {
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
			if (_data->Input.spriteClick(_menu, sf::Mouse::Left, _data->window)) {
				this->_data->statemachine.Addsref(sref(new MainMenu(_data)), true);
			}
		}
	}

	void GameOver::_update(float deltaTime) {

	}

	void GameOver::_draw(float deltaTime) {
		this->_data->window.clear(sf::Color::Blue);
		this->_data->window.draw(this->_bg);
		this->_data->window.draw(this->_menu);
		this->_data->window.display();
	}
};