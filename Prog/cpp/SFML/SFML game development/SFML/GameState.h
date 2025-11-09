#pragma once
#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "StateStack.h"
#include "World.h"
#include "Player.h"

class GameState : public State
{
public:
				 GameState(StateStack& stack, Context context);

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();

private:
	World   mWorld; 
	Player	mPlayer;
};