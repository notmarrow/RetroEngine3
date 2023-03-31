#include "ScoreHud.h"

namespace Retro {
	ScoreHud::ScoreHud(GDref data) : _data(data){
		_scoreT.setFont(_data->Asset.getFont("mainfont"));
		_scoreT.setString("0");
		_scoreT.setCharacterSize(128);
		_scoreT.setFillColor(sf::Color::Black);
		_scoreT.setOrigin(_scoreT.getGlobalBounds().width / 2, _scoreT.getGlobalBounds().height / 2);
		_scoreT.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 6);
		// Se posiciona el texto de puntuación y se selecciona su color, fuente y tamaño
	}
	void ScoreHud::_draw() {
		_data->window.draw(_scoreT);
	}
	void ScoreHud::scoreUpdate(int score) {
		_scoreT.setString(std::to_string(score));
	} // Cambia el texto que mostrará el scorehud

};