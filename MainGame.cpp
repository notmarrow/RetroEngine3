#include "MainGame.h"
#include "MainMenu.h"
namespace Retro {
	MainGame::MainGame(GDref data) : _data(data) {}
	void MainGame::_init() {
		this->_data->Asset.TextureLoad("home", HOME_PATH);
		this->_data->Asset.TextureLoad("cactusl", CACTUSL_PATH);
		this->_data->Asset.TextureLoad("cactuss", CACTUSS_PATH);
		this->_data->Asset.TextureLoad("bird", BIRD1_PATH);
		this->_data->Asset.TextureLoad("dino2", DINO2_PATH);
		this->_data->Asset.FontLoad("mainfont", FONT_PATH);
		
		obstacles = new Obstacle(_data);
		dino = new Player(_data);
		scorehud = new ScoreHud(_data);

		_bg.setTexture(this->_data->Asset.getTexture("mainbackground"));
		_home.setTexture(this->_data->Asset.getTexture("home"));

		_home.setPosition(30, 30);
		score = 0;
		scorehud->scoreUpdate(score);
		gameState = GameStates::gameReady;
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
			}
			if (_data->Input.spriteClick(_bg, sf::Mouse::Left, _data->window)) {
				if (gameState != gameOver) {
					dino->jump();
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
			}
			if (_clockbird.getElapsedTime().asSeconds() > BIRD_SPAWN_SPEED) {
				obstacles->spawnbird();
				obstacles->spawnScoreCheck();
				_clockbird.restart();
			}
			dino->anim(deltaTime);
			dino->_update(deltaTime);
			std::vector<sf::Sprite> obsSprites = obstacles->getSpriteVect();
			for (int i = 0; i < obsSprites.size(); i++) {
				if (collider.checkCollision(dino->getSprite(), 0.75f , obsSprites.at(i), 0.75f)) {
					gameState = GameStates::gameOver;
				}
			}

			std::vector<sf::Sprite> &scoreSprites = obstacles->getScoreVect();
			for (int i = 0; i < scoreSprites.size(); i++) {
				if (collider.checkCollision(dino->getSprite(), 0.75f, scoreSprites.at(i), 1000.0f)) {
					score += 100;
					scorehud->scoreUpdate(score);
					scoreSprites.erase(scoreSprites.begin() + i);
				}
			}
		}
	}

	void MainGame::_draw(float deltaTime) {
		this->_data->window.clear(sf::Color::Blue);
		this->_data->window.draw(this->_bg);
		this->_data->window.draw(this->_home);
		obstacles->_draw();
		dino->_draw();
		scorehud->_draw();
		this->_data->window.display();
	}
};