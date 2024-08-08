#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> m_Textures;
	std::map<std::string, sf::SoundBuffer> m_SoundBuffer;
	std::map<std::string, sf::Font> m_Fonts;

	static AssetManager* sInstance;
public:
	AssetManager();

	static sf::Texture& getTexture(std::string const& filename);
	static sf::SoundBuffer& getSoundBuffer(std::string const& filename);
	static sf::Font& getFont(std::string const& filename);
};