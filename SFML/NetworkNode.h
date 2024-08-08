#pragma once

#include <deque>

#include "SceneNode.h"
#include "NetworkProtocol.h"

class NetworkNode : public SceneNode
{
public:
	NetworkNode();

	void					notifyGameAction(GameActions::Type type, sf::Vector2f position);
	bool					pollGameAction(GameActions::Action& out);

	virtual unsigned int	getCategory() const;


private:
	std::queue<GameActions::Action>	mPendingActions;
};