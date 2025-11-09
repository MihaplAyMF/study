#pragma once

#include "SceneNode.h"
#include "Particle.h"

class ParticleNode;

class EmmiterNode : public SceneNode
{
public:
	explicit	 EmmiterNode(Particle::Type type);

private: 
	virtual void updateCurrent(sf::Time dt, CommandQueue& commands);

	void		 emitParticle(sf::Time dt);

	sf::Time	   mAccumulatedTime;
	Particle::Type mType;
	ParticleNode*  mParticleSystem;

};