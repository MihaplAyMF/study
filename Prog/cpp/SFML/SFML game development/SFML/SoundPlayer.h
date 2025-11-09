#pragma once;

#include <list>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.h"

class SoundPlayer : private sf::NonCopyable
{
public:
	SoundPlayer();
	
	void play(SoundEffect effect);
	void play(SoundEffect effect, sf::Vector2f possition);

	void			removeStoppedSounds();
	void			setListenerPosition(sf::Vector2f position);
	sf::Vector2f	getListenerPosition() const;
	
private:
	SoundBufferHolder		mSoundBuffers;
	std::list<sf::Sound>	mSounds;
};