#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Container.h"

class GameOverState : public State
{
public:
				 GameOverState(StateStack& stack, Context context, const std::string& text);

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();

private:
	sf::Text mGameOverText;
	sf::Time mElapsedTime;
};

