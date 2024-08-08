#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Container.h"

class MenuState : public State
{
public:
	MenuState(StateStack& stack, Context context);

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();

private:
	sf::Sprite			  mBackgroundSprite;
	GUI::Container		  mGUIContainer;
};