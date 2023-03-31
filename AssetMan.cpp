#include "AssetMan.h"

namespace Retro {
	void AssetMan::TextureLoad(std::string name, std::string filepath) {
		sf::Texture texture;
		if (texture.loadFromFile(filepath))
		{
			this->_texturemap[name] = texture; // A�ade la textura a el mapa de texturas
		}
		else {
			std::cout << "Texture couldn't be loaded";
		}
	}
	sf::Texture& AssetMan::getTexture(std::string name) {
		if (this->_texturemap.find(name) != this->_texturemap.end()) {
			return this->_texturemap.at(name); // Devuelve la textura en la posici�n con el nombre indicado
		}
		else
		{
			std::cout << "Texture couldn't be found on map";
		}
	}

	void AssetMan::FontLoad(std::string name, std::string filepath) {
		sf::Font font;
		if (font.loadFromFile(filepath))
		{
			this->_fontmap[name] = font; // A�ade la fuente a el mapa de texturas
		}
	}
	sf::Font& AssetMan::getFont(std::string name) {
		return this->_fontmap.at(name); // Devuelve la fuente en la posici�n con el nombre indicado
	}
};