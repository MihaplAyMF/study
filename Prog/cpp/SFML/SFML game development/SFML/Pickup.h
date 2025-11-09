#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Aircraft.h"

#include "ResourceIdentifiers.h"
#include "Command.h"

class Pickup : public Entity
{
public:
	enum Type
	{
		HealthRefill,
		MissileRefill,
		FireSpread,
		FireRate,
		TypeCount
	};

						  Pickup(Type type, const TextureHolder& textures);

	virtual unsigned int  getCategory() const;
	virtual sf::FloatRect getBoundingRect() const;

	void				  apply(Aircraft& player) const;

protected: 
	virtual void		  drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type	   mType;
	sf::Sprite mSprite;
};