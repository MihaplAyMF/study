#include "Game.h"
#include "Utility.hpp"

#include "State.h"
#include "StateIdentifiers.h"

#include "TitleState.h"
#include "GameState.h"
#include "MultiplayerGameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "SettingsState.h"
#include "GameOverState.h"

const sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(1024, 768), "SFML Application", sf::Style::Close)
	, mTextures()
	, mFonts()
	, mMusic()
	, mSounds()
	, mKeyBinding1(1)
	, mKeyBinding2(2)
	, mStateStack(State::Context(mWindow, mTextures, mFonts, mMusic, mSounds, mKeyBinding1, mKeyBinding2))
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
{ 
	mFonts.load(Fonts::Main, "Media/Fonts/Sansation.ttf");

	mTextures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");
	mTextures.load(Textures::Buttons,     "Media/Textures/Buttons.png");

	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(15);

	registerStates();
	mStateStack.pushState(States::Menu);
}

void Game::handleInput()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		mStateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void Game::render()
{
	mWindow.clear();
	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if(mStatisticsUpdateTime >= sf::seconds(1.f))
	{
		mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));
		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<MenuState>(States::Menu);
	mStateStack.registerState<GameState>(States::Game);
	mStateStack.registerState<MultiplayerGameState>(States::HostGame, true);
	mStateStack.registerState<MultiplayerGameState>(States::JoinGame, false);
	mStateStack.registerState<PauseState>(States::Pause);
	mStateStack.registerState<PauseState>(States::NetworkPause, true);
	mStateStack.registerState<SettingState>(States::Settings);
	mStateStack.registerState<GameOverState>(States::GameOver, "Mission Failed!");
	mStateStack.registerState<GameOverState>(States::MissionSuccess, "Mission Successful!");
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while(mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while(timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			handleInput();
			update(timePerFrame);

			if(mStateStack.isEmpty())
				mWindow.close();
		}

		updateStatistics(dt);
		render();
	}
}
