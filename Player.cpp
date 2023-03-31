#include "Player.h"

namespace Retro {
	Player::Player(GDref data) : _data(data) {
		animIterator = 0;
		animFrames.push_back(_data->Asset.getTexture("dino1"));
		animFrames.push_back(_data->Asset.getTexture("dino2"));
		playerSprite.setTexture(animFrames.at(animIterator));
		// Carga de texturas
		playerSprite.setPosition(_data->window.getSize().x / 8 - playerSprite.getGlobalBounds().width / 2, _data->window.getSize().y - playerSprite.getGlobalBounds().height - 10);
		dinoState = DINO_STATE_STILL; // Se registra que el jugador esta quieto
	}
	void Player::_draw() {
		_data->window.draw(playerSprite);
	}
	void Player::anim(float deltaTime) {
		if (animClock.getElapsedTime().asSeconds() > DINO_ANIM_SPEED / animFrames.size()) {
			if (animIterator < animFrames.size() - 1) {
				animIterator++;
			} // Si el vector aún tiene frames se pasa al siguiente
			else {
				animIterator = 0;
			} // Si no, se reinicia el iterador
			playerSprite.setTexture(animFrames.at(animIterator)); // Se cambia la textura al frame actual
			animClock.restart(); // Se reinicia el reloj
		}
	}
	void Player::_update(float deltaTime) {
		if (DINO_STATE_FALL == dinoState) {
			playerSprite.move(0, GRAVITY * deltaTime);
		} // Si el jugador esta callendo la gravedad lo mueve hacia abajo
		else if (DINO_STATE_JUMP == dinoState) {
			playerSprite.move(0, -JUMP_SPEED * deltaTime);
		} // Si el jugador esta saltando la gravedad lo mueve hacia arriba
		if (jumpClock.getElapsedTime().asSeconds() > JUMP_DURATION) { // Se checa el tiempo de salto con el tiempo dado
			jumpClock.restart(); // Se reinica el reloj de salto
			if (DINO_STATE_JUMP == dinoState) {
				dinoState = DINO_STATE_FALL;
			} // Si el jugador estaba saltando se inica la caída
			else if (DINO_STATE_FALL == dinoState) {
				dinoState = DINO_STATE_STILL;
				playerSprite.setPosition(_data->window.getSize().x / 8 - playerSprite.getGlobalBounds().width / 2, _data->window.getSize().y - playerSprite.getGlobalBounds().height - 10);
			} // Si el jugador estaba cayendo se hace que quede quieto
			/* 
				El setPosition se usa para reiniciar la posición del jugador debido a un bug en el que el jugador podía
				escalar la pantalla
			*/
		}
	}
	void Player::jump() {
		if (DINO_STATE_STILL == dinoState) {
			jumpClock.restart(); 
			dinoState = DINO_STATE_JUMP;
		} // Si el jugador esta quieto y se presiona el botón de salto, se cambia el estado a salto y se reinicia el reloj
	}
};