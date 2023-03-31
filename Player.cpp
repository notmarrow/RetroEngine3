#include "Player.h"

namespace Retro {
	Player::Player(GDref data) : _data(data) {
		animIterator = 0;
		animFrames.push_back(_data->Asset.getTexture("dino1"));
		animFrames.push_back(_data->Asset.getTexture("dino2"));
		playerSprite.setTexture(animFrames.at(animIterator));
		playerSprite.setPosition(_data->window.getSize().x / 8 - playerSprite.getGlobalBounds().width / 2, _data->window.getSize().y - playerSprite.getGlobalBounds().height - 10);
		dinoState = DINO_STATE_STILL;
	}
	void Player::_draw() {
		_data->window.draw(playerSprite);
	}
	void Player::anim(float deltaTime) {
		if (animClock.getElapsedTime().asSeconds() > DINO_ANIM_SPEED / animFrames.size()) {
			if (animIterator < animFrames.size() - 1) {
				animIterator++;
			}
			else {
				animIterator = 0;
			}
			playerSprite.setTexture(animFrames.at(animIterator));
			animClock.restart();
		}
	}
	void Player::_update(float deltaTime) {
		if (DINO_STATE_FALL == dinoState) {
			playerSprite.move(0, GRAVITY * deltaTime);
		}
		else if (DINO_STATE_JUMP == dinoState) {
			playerSprite.move(0, -JUMP_SPEED * deltaTime);
		}
		if (jumpClock.getElapsedTime().asSeconds() > JUMP_DURATION) {
			jumpClock.restart();
			if (DINO_STATE_JUMP == dinoState) {
				dinoState = DINO_STATE_FALL;
			}
			else if (DINO_STATE_FALL == dinoState) {
				dinoState = DINO_STATE_STILL;
				playerSprite.setPosition(_data->window.getSize().x / 8 - playerSprite.getGlobalBounds().width / 2, _data->window.getSize().y - playerSprite.getGlobalBounds().height - 10);
			}
		}
	}
	void Player::jump() {
		if (DINO_STATE_STILL == dinoState) {
			jumpClock.restart();
			dinoState = DINO_STATE_JUMP;
		}
	}
};