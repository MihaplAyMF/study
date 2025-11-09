#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Container.h"

class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context, bool letUpdatesThrough = false);

	~PauseState();

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();

private:
	sf::Sprite	    mBackgroundSprite;
	sf::Text	    mPausedText;
	GUI::Container  mGUIContainer;		
	bool		    mLetUpdatesThrough;

};