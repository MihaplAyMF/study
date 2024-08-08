#pragma once

#include <deque>

#include <SFML/Graphics/VertexArray.hpp>

#include "SceneNode.h"
#include "Particle.h"
#include "ResourceIdentifiers.h"

class ParticleNode : public SceneNode
{
public:
						 ParticleNode(Particle::Type type, const TextureHolder& textures);

	void				 addParticle(sf::Vector2f position);
	Particle::Type		 getParticleType() const;
	virtual unsigned int getCategory() const;

private:
	virtual void		 updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual void		 drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	void				 addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
	void				 computeVertices() const;
	
	std::deque<Particle>	mParticles;
	const sf::Texture&		mTextures;
	Particle::Type			mType;

	mutable sf::VertexArray mVertexArray;
	mutable bool			mNeedVertexUpdate;
};