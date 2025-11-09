#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include "MenuState.h"
#include "Utility.hpp"
#include "ResourceHolder.hpp"
#include "Button.h"
#include "MusicPlayer.h"

MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(context);
	playButton->setPosition(412, 200);
	playButton->setText("Play");
	playButton->setCallback([this]() 
	{
		requestStackPop();
		requestStackPush(States::Game);
	});

	auto hostPlayButton = std::make_shared<GUI::Button>(context);
	hostPlayButton->setPosition(412, 250);
	hostPlayButton->setText("Host");
	hostPlayButton->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::HostGame);
	});

	auto joinPlayButton = std::make_shared<GUI::Button>(context);
	joinPlayButton->setPosition(412, 300);
	joinPlayButton->setText("Join");
	joinPlayButton->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::JoinGame);
	});

	auto settingsButton = std::make_shared<GUI::Button>(context);
	settingsButton->setPosition(412, 350);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this]()
	{
		requestStackPush(States::Settings);
	});

	auto exitButton = std::make_shared<GUI::Button>(context);
	exitButton->setPosition(412, 400);
	exitButton->setText("Exit");
	exitButton->setCallback([this]()
	{
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(hostPlayButton);
	mGUIContainer.pack(joinPlayButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);

	context.music->play(Music::MenuTheme);
}

bool MenuState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return true;
}

bool MenuState::update(sf::Time dt)
{
	return true;
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	
	window.setView(window.getDefaultView());
	
	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

