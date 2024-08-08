#pragma once

#include <vector>
#include <map>
#include <functional>
#include <utility>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Event.hpp>

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"
#include "State.h"

namespace sf
{
	class Event;
	class RenderWindow;
}

class StateStack : private sf::NonCopyable
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear,
	};

public:
	explicit StateStack(State::Context context);

	template<typename T>
	void registerState(States stateID);

	template<typename T, typename Param>
	void registerState(States stateID, Param arg);

	void update(sf::Time dt);
	void draw();
	void handleEvent(const sf::Event& event);

	void pushState(States stateID);
	void popState();
	void clearStates();

	bool isEmpty() const;

private:
	State::Ptr createState(States stateID);
	void applyPendingChanges();

	struct PendingChange
	{
		explicit PendingChange(Action action, States stateID = States::None);

		Action action;
		States stateID;
	};

	std::vector<State::Ptr> mStack;
	std::vector<PendingChange> mPendingList;
	State::Context mContext;
	std::map<States, std::function<State::Ptr()>> mFactories;
};

template<typename T>
void StateStack::registerState(States stateID)
{
	mFactories[stateID] = [this]()
	{
		return State::Ptr(new T(*this, mContext));
	};
}

template<typename T, typename Param>
void StateStack::registerState(States stateID, Param arg)
{
	mFactories[stateID] = [this, arg] ()
	{
		return State::Ptr(new T(*this, mContext, arg));
	};
}
