#pragma once
#include "appincludes.h"
namespace Retro {
	class AssetMan {
	public: 
		AssetMan() {};
		~AssetMan() {};
		void TextureLoad(std::string name, std::string filepath);
		sf::Texture& getTexture(std::string name); 
		
		void FontLoad(std::string name, std::string filepath);
		sf::Font& getFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _texturemap;
		std::map<std::string, sf::Font> _fontmap;
	};
};

