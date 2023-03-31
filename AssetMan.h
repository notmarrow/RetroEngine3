#pragma once
#include "appincludes.h"
namespace Retro {
	/*
		La clase AssetMan (asset manager) se utiliza para controlar los recursos que se utilizaran en el juego como 
		fuentes y texturas
	*/
	class AssetMan {
	public: 
		AssetMan() {};
		~AssetMan() {};
		void TextureLoad(std::string name, std::string filepath); // Usado para cargar texturas al mapa de texturas
		sf::Texture& getTexture(std::string name); // Usado para regresar referencias a texturas en el mapa de texturas
		
		void FontLoad(std::string name, std::string filepath); // Usado para cargar fuentes al mapa de fuentes
		sf::Font& getFont(std::string name); // Usado para regresar referencias a fuentes en el mapa de fuentes

	private:
		std::map<std::string, sf::Texture> _texturemap; // Mapa de texturas
		std::map<std::string, sf::Font> _fontmap; // Mapa de fuentes
	};
};

