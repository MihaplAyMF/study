#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::getTexture(std::string const& filename)
{
	auto& texMap = sInstance->m_Textures;

	// See if the texture is already loaded
	auto pairFound = texMap.find(filename);

	// If yes, return texture
	if(pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else // Else, load the texture and return it
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::SoundBuffer& AssetManager::getSoundBuffer(std::string const& filename)
{
	auto& sBufferMap = sInstance->m_SoundBuffer;

	// See if the texture is already loaded
	auto pairFound = sBufferMap.find(filename);

	// If yes, return texture
	if(pairFound != sBufferMap.end())
	{
		return pairFound->second;
	}
	else // Else, load the texture and return it
	{
		auto& sBuffer = sBufferMap[filename];
		sBuffer.loadFromFile(filename);
		return sBuffer;
	}
}

sf::Font& AssetManager::getFont(std::string const& filename)
{
	auto& fontMap = sInstance->m_Fonts;

	// See if the texture is already loaded
	auto pairFound = fontMap.find(filename);

	// If yes, return texture
	if(pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else // Else, load the texture and return it
	{
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}
