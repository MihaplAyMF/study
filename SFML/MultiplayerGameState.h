#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>

#include "State.h"
#include "World.h"
#include "Player.h"
#include "GameServer.h"
#include "NetworkProtocol.h"

class MultiplayerGameState : public State
{
public:
	MultiplayerGameState(StateStack& stack, Context context, bool isHost);

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();

	virtual void onActivate();
	void		 onDestroy();

	void		 disableAllRealtimeActions();


private:
	typedef std::unique_ptr<Player> PlayerPtr;

	void updateBroadcastMessage(sf::Time elapsedTime);
	void handlePacket(sf::Int32 packetType, sf::Packet& packet);

	World			  mWorld;
	sf::RenderWindow& mWindow;
	TextureHolder&    mTextureHolder;

	std::map<int, PlayerPtr>	mPlayers;
	std::vector<sf::Int32>		mLocalPlayerIdentifiers;
	std::unique_ptr<GameServer> mGameServer;
	std::vector<std::string>	mBroadcasts;
	sf::TcpSocket				mSocket;
	sf::Clock				    mTickClock;

	sf::Text  mBroadcastText;
	sf::Time  mBroadcastElapsedTime;

	sf::Text  mPlayerInvitationText;
	sf::Time  mPlayerInvitationTime;

	sf::Time  mClientTimeout;
	sf::Time  mTimeSinceLastPacket;

	sf::Text  mFailedConnectionText;
	sf::Clock mFailedConnectionClock;

	bool mActiveState;
	bool mHasFocus;
	bool mHost;
	bool mGameStarted;
	bool mConnected;
	
};