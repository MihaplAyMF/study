#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "StateStack.h"

class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();

private:
	sf::Sprite mBackgroundSprite;
	sf::Text   mText;
	bool	   mShowText;
	sf::Time   mTextEffectTime;
};