#include "SplashScreen.h"
#include "MainMenu.h"
namespace Retro {
	SplashScreen::SplashScreen(GDref data) : _data(data){}

	void SplashScreen::_init() {
		this->_data->Asset.TextureLoad("splashbg", SPLASH_BACKGROUND_PATH);
		this->_data->Asset.TextureLoad("dino1", DINO1_PATH);
		this->_data->Asset.TextureLoad("dino2", DINO2_PATH); // Asignan las texturas a un mapa usando el AssetManager
		texturevec.push_back(_data->Asset.getTexture("dino1"));
		texturevec.push_back(_data->Asset.getTexture("dino2")); // Actualizan el vector de texturas con los frames de la animacion
		_bg.setTexture(this->_data->Asset.getTexture("splashbg"));
		_dino.setTexture(this->_data->Asset.getTexture("dino1")); // Asigna la textura inicial
		_dino.setPosition((SCREEN_WIDTH / 2) - (_dino.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_dino.getGlobalBounds().height / 2));
		animator = new Animator(texturevec); // Crea el objeto animador con el vector de texturas
	}

	void SplashScreen::_inputManager() {
		sf::Event event; 
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
		}
	}

	void SplashScreen::_update(float deltaTime) {
		animator->animate(0.2f); // Activa el método de animación
		_dino.setTexture(animator->getCurrentSprite()); // Actualiza la textura con el método de animación
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_TIME) {
			this->_data->statemachine.Addsref(sref(new MainMenu(_data)), true); // Actualiza el estado del juego para pasar al menu principal
		}
	}

	void SplashScreen::_draw(float deltaTime) {
		this->_data->window.clear(sf::Color::Blue);
		this->_data->window.draw(this->_bg);
		this->_data->window.draw(this->_dino);
		this->_data->window.display();
	}
};