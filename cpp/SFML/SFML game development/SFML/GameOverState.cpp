#include "GameOverState.h"
#include "Utility.hpp"
#include "Player.h"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

GameOverState::GameOverState(StateStack& stack, Context context, const std::string& text)
	: State(stack, context)
	, mGameOverText()
	, mElapsedTime(sf::Time::Zero)
{
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f windowSize(context.window->getSize());

	mGameOverText.setFont(font);
	mGameOverText.setString(text);
	mGameOverText.setCharacterSize(70);
	centerOrigin(mGameOverText);
	mGameOverText.setPosition(0.5f * windowSize.x, 0.4 * windowSize.y);
}

bool GameOverState::handleEvent(const sf::Event& event)
{
	return false;
}

bool GameOverState::update(sf::Time dt)
{
	mElapsedTime += dt;
	if(mElapsedTime > sf::seconds(3))
	{
		requestStateClear();
		requestStackPush(States::Menu);
	}
	return false;
}

void GameOverState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(mGameOverText);
}

