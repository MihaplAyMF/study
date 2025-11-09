#include "EmmiterNode.h"
#include "ParticleNode.h"
#include "CommandQueue.h"
#include "Command.h"

EmmiterNode::EmmiterNode(Particle::Type type)
	: SceneNode()
	, mAccumulatedTime(sf::Time::Zero)
	, mType(type)
	, mParticleSystem(nullptr)
{ }

void EmmiterNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if(mParticleSystem)
	{
		emitParticle(dt);
	}
	else
	{
		auto finder = [this] (ParticleNode& container, sf::Time)
		{
			if(container.getParticleType() == mType)
				mParticleSystem = &container;
		};
		
		Command command;
		command.category = Category::ParticleSystem;
		command.action = derivedAction<ParticleNode>(finder);

		commands.push(command);
	}
}

void EmmiterNode::emitParticle(sf::Time dt)
{
	const float emissionRate = 30.f;
	const sf::Time interval = sf::seconds(1.f) / emissionRate;

	mAccumulatedTime += dt;

	while(mAccumulatedTime > interval)
	{
		mAccumulatedTime -= interval;
		mParticleSystem->addParticle(getWorldPosition());
	}
}
