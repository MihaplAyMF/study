#include "GameState.h"
#include "MusicPlayer.h"

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mWorld(*context.window, *context.fonts, *context.sounds)
	, mPlayer(nullptr, 1, context.keys1)
{ 
	mWorld.addAircraft(1);
	mPlayer.setMissionStatus(Player::MissionRunning);

	context.music->play(Music::MissionTheme);
}

bool GameState::handleEvent(const sf::Event & event)
{
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleEvent(event, commands);

	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(States::Pause);

	return true;
}

bool GameState::update(sf::Time dt)
{
	mWorld.update(dt);

	if(!mWorld.hasAlivePlayer())
	{	
		mPlayer.setMissionStatus(Player::MissionFailure);
		requestStackPush(States::GameOver);
	}
	else if(mWorld.hasPlayerReachedEnd())
	{
		mPlayer.setMissionStatus(Player::MissionSuccess);
		requestStackPush(States::MissionSuccess);
	}

	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleRealtimeInput(commands);

	return true;
}

void GameState::draw()
{
	mWorld.draw();
}