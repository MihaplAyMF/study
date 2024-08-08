#include <string>
#include <algorithm>
#include <map>

#include <SFML/Network/Packet.hpp>

#include "Player.h"
#include "Aircraft.h"
#include "NetworkProtocol.h"
#include "CommandQueue.h"

using namespace std::placeholders;

struct AircraftMover
{
	AircraftMover(float vx, float vy, int identifier)
		: velocity(vx, vy)
		, aircraftID(identifier)
	{ }

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		if(aircraft.getIdentifier() == aircraftID)
			aircraft.accelerate(velocity * aircraft.getMaxSpeed());
	}

	sf::Vector2f velocity;
	int aircraftID;
};

struct AircraftFireTrigger
{
	AircraftFireTrigger(int identifier)
		: aircraftID(identifier)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		if(aircraft.getIdentifier() == aircraftID)
			aircraft.fire();
	}

	int aircraftID;
};

struct AircraftMissileTrigger
{
	AircraftMissileTrigger(int identifier)
		: aircraftID(identifier)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		if(aircraft.getIdentifier() == aircraftID)
			aircraft.launchMissile();
	}

	int aircraftID;
};

Player::Player(sf::TcpSocket* socket, sf::Int32 identifier, const KeyBinding* binding) 
	: mKeyBinding(binding)
	, mCurrentMissionStatus(MissionRunning)
	, mIdentifier(identifier)
	, mSocket(socket)
{
	initializeActions();

	for(auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if(event.type == sf::Event::KeyPressed)
	{
		Action action;
		if(mKeyBinding && mKeyBinding->checkAction(event.key.code, action) && isRealtimeAction(action))
		{
			if(mSocket)
			{
				sf::Packet packet;
				packet << static_cast<sf::Int32>(Client::PlayerEvent);
				packet << mIdentifier;
				packet << static_cast<sf::Int32>(action);
				mSocket->send(packet);
			}
			else
			{
				commands.push(mActionBinding[action]);
			}
		}
	}

	if((event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) && mSocket)
	{
		Action action;
		if(mKeyBinding && mKeyBinding->checkAction(event.key.code, action) && isRealtimeAction(action))
		{
			sf::Packet packet;
			packet << static_cast<sf::Int32>(Client::PlayerRealtimeChange);
			packet << mIdentifier;
			packet << static_cast<sf::Int32>(action);
			packet << (event.type == sf::Event::KeyPressed);
			mSocket->send(packet);
		}
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	if((mSocket && isLocal()) || !mSocket)
	{
		std::vector<Action> activeActions = mKeyBinding->getRealtimeActions();
		for(Action action : activeActions)
			commands.push(mActionBinding[action]);
	}
}

void Player::handleRealtimeNetworkInput(CommandQueue& commands)
{
	if(mSocket && !isLocal())
	{
		for(auto pair : mActionProxies)
		{
			if(pair.second && isRealtimeAction(pair.first))
				commands.push(mActionBinding[pair.first]);
		}
	}
}

void Player::handleNetworkEvent(Action action, CommandQueue& commands)
{
	commands.push(mActionBinding[action]);
}

void Player::handleNetworkRealtimeChange(Action action, bool actionEnabled)
{
	mActionProxies[action] = actionEnabled;
}

void Player::setMissionStatus(MissionStatus status)
{
	mCurrentMissionStatus = status;
}

Player::MissionStatus Player::getMissionStatus() const
{
	return mCurrentMissionStatus;
}

void Player::disableAllRealtimeActions()
{
	for(auto& action : mActionProxies)
	{
		sf::Packet packet;
		packet << static_cast<sf::Int32>(Client::PlayerRealtimeChange);
		packet << mIdentifier;
		packet << static_cast<sf::Int32>(action.first);
		packet << false;
		mSocket->send(packet);
	}
}

bool Player::isLocal() const
{
	return mKeyBinding != nullptr;
}

void Player::initializeActions()
{
	mActionBinding[PlayerAction::MoveLeft].action		= derivedAction<Aircraft>(AircraftMover(-1, 0, mIdentifier));
	mActionBinding[PlayerAction::MoveRight].action		= derivedAction<Aircraft>(AircraftMover(+1, 0, mIdentifier));
	mActionBinding[PlayerAction::MoveUp].action			= derivedAction<Aircraft>(AircraftMover(0, -1, mIdentifier));
	mActionBinding[PlayerAction::MoveDown].action		= derivedAction<Aircraft>(AircraftMover(0, +1, mIdentifier));
	mActionBinding[PlayerAction::Fire].action			= derivedAction<Aircraft>(AircraftFireTrigger(mIdentifier));
	mActionBinding[PlayerAction::LaunchMissile].action	= derivedAction<Aircraft>(AircraftMissileTrigger(mIdentifier));
}
