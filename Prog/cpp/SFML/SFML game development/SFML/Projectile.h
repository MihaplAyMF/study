#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.h"
#include "Command.h"
#include "ResourceIdentifiers.h"

class Aircraft;

class Projectile : public Entity
{
public:
	enum Type
	{
		AlliedBullet,
		EnemyBullet,
		Missile,
		TypeCount
	};
	
						  Projectile(Type type, const TextureHolder& textures);

	void				  guideTowards(sf::Vector2f position);
	bool				  isGuided() const;

	virtual unsigned int  getCategory() const;
		virtual sf::FloatRect getBoundingRect() const;
	float				  getMaxSpeed() const;
	int					  getDamage() const;

private:
	virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	Type		 mType;
	sf::Sprite   mSprite;
	sf::Vector2f mTargetDirection;
};