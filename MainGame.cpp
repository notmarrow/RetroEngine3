#include "MainGame.h"
#include "MainMenu.h"
#include "GameOver.h"
namespace Retro {
	MainGame::MainGame(GDref data) : _data(data) {}
	void MainGame::_init() {
		if (!pointSoundBuffer.loadFromFile(POINT_SOUND_PATH)) {
			std::cout << "Couldn't load sound effect" << std::endl; // Se checa si es posible cargar el sonido al buffer
		}
		pointSound.setBuffer(pointSoundBuffer);
		// Se inicializa el sonido con el buffer

		this->_data->Asset.TextureLoad("home", HOME_PATH);
		this->_data->Asset.TextureLoad("cactusl", CACTUSL_PATH);
		this->_data->Asset.TextureLoad("cactuss", CACTUSS_PATH);
		this->_data->Asset.TextureLoad("bird", BIRD1_PATH);
		this->_data->Asset.TextureLoad("bird2", BIRD2_PATH);
		this->_data->Asset.FontLoad("mainfont", FONT_PATH); // Se cargan las texturas al mapa
		
		obstacles = new Obstacle(_data);
		dino = new Player(_data);
		scorehud = new ScoreHud(_data); // Se crean objetos para controlar los elementos del juego

		_bg.setTexture(this->_data->Asset.getTexture("mainbackground"));
		_home.setTexture(this->_data->Asset.getTexture("home"));

		_home.setPosition(30, 30);
		score = 0;
		scorehud->scoreUpdate(score);
		gameState = GameStates::gameReady; // Se activa el estado de inicio del juego
	}

	void MainGame::_inputManager() {
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
			if (_data->Input.spriteClick(_home, sf::Mouse::Left, _data->window)) {
				this->_data->statemachine.Addsref(sref(new MainMenu(_data)), true);
				// Se usa para checar si el jugador presiona el botón para regresar al menú
			}
			if (_data->Input.spriteClick(_bg, sf::Mouse::Left, _data->window)) {
				if (gameState != gameOver) {
					dino->jump();
					// Si el jugador presiona en cualquier lugar sobre el fondo se activa el salto del personaje
				}
			}
		}
	}

	void MainGame::_update(float deltaTime) {
		if (gameState != GameStates::gameOver) {
			obstacles->_move(deltaTime);
			if (_clockcactus.getElapsedTime().asSeconds() > CACTUS_SPAWN_SPEED) {
				obstacles->spawncactus();
				obstacles->spawnScoreCheck();
				_clockcactus.restart();
			} // Se checa el tiempo para spawnear cactus
			if (_clockbird.getElapsedTime().asSeconds() > BIRD_SPAWN_SPEED) {
				obstacles->spawnbird();
				obstacles->spawnScoreCheck();
				_clockbird.restart();
			} // Se checa el tiempo para spawnear pájaros
			dino->anim(deltaTime);
			dino->_update(deltaTime);
			// Actualizaciones del dinosaurio
			std::vector<sf::Sprite> obsSprites = obstacles->getSpriteVect();
			// Vector utilizado para checar las colisiones con el vector que contiene los obstáculos
			for (int i = 0; i < obsSprites.size(); i++) {
				if (collider.checkCollision(dino->getSprite(), 0.75f , obsSprites.at(i), 0.75f)) {
					gameState = GameStates::gameOver;
					_clockcactus.restart();
				}
			} // Se itera sobre el vector de obstáculos para checar cada uno por colisiones

			std::vector<sf::Sprite> &scoreSprites = obstacles->getScoreVect();
			for (int i = 0; i < scoreSprites.size(); i++) {
				if (collider.checkCollision(dino->getSprite(), 0.75f, scoreSprites.at(i), 1000.0f)) {
					// El tamaño en y se hace de 1000 para asegurar que el jugador lo tocará cuando pase sobre un obstáculo
					pointSound.play();
					score += 100;
					scorehud->scoreUpdate(score);
					scoreSprites.erase(scoreSprites.begin() + i);
				}
			} // Se itera sobre el vector de triggers de puntuación para checar cada uno por colisiones
		}
		if (gameState == GameStates::gameOver){
			if (_clockcactus.getElapsedTime().asSeconds() > GAME_OVER_TIME) {
				_data->statemachine.Addsref(sref(new GameOver(_data, score)), true);
			}
		}
	}

	void MainGame::_draw(float deltaTime) {
		this->_data->window.clear(sf::Color::Blue);
		this->_data->window.draw(this->_bg);	
		obstacles->_draw();
		dino->_draw();
		scorehud->_draw();
		this->_data->window.draw(this->_home);
		this->_data->window.display();
	}
};