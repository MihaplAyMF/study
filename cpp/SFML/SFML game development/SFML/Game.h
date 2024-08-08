#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.h"
#include "Player.h"
#include "StateStack.h"
#include "MusicPlayer.h"
#include "SoundPlayer.h"
#include "KeyBinding.h"


class Game
{
public:
	Game();
	void run();

private:
	void handleInput();
	void update(sf::Time dt);
	void render();
	
	void updateStatistics(sf::Time elapsedTime);
	void registerStates();

private:
	static const sf::Time timePerFrame;

	sf::RenderWindow	mWindow;
	TextureHolder		mTextures;
	FontHolder			mFonts;
	MusicPlayer			mMusic;
	SoundPlayer			mSounds;

	KeyBinding			mKeyBinding1;
	KeyBinding			mKeyBinding2;
	StateStack			mStateStack;

	sf::Text			mStatisticsText;
	sf::Time			mStatisticsUpdateTime;
	std::size_t			mStatisticsNumFrames;
};

