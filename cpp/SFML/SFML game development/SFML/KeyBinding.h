#pragma once

#include <map>
#include <vector>

#include <SFML/Window/Keyboard.hpp>

namespace PlayerAction
{
	enum Type
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		Fire,
		LaunchMissile,
		Count
	};
}

class KeyBinding
{
public:
	typedef PlayerAction::Type Action;


public:
	explicit				KeyBinding(int controlPreconfiguration);

	void					assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key		getAssignedKey(Action action) const;

	bool					checkAction(sf::Keyboard::Key key, Action& out) const;
	std::vector<Action>		getRealtimeActions() const;


private:
	void					initializeActions(); 

	std::map<sf::Keyboard::Key, Action>		mKeyMap;
};

bool					isRealtimeAction(PlayerAction::Type action);
