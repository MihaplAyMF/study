#include <cassert>
#include <cmath>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Projectile.h"
#include "EmmiterNode.h"
#include "DataTables.h"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

namespace
{
	const std::vector<ProjectileData> Table = initializeProjectileData();
}

Projectile::Projectile(Type type, const TextureHolder& textures)
	: Entity(1)
	, mType(type)	
	, mSprite(textures.get(Table[type].texture), Table[type].textureRect)
	, mTargetDirection()
{
	centerOrigin(mSprite);

	if(isGuided())
	{
		std::unique_ptr<EmmiterNode> smoke = std::make_unique<EmmiterNode>(Particle::Smoke);
		smoke->setPosition(0.f, getBoundingRect().height / 2.f);
		attachChild(std::move(smoke));

		std::unique_ptr<EmmiterNode> propellant = std::make_unique<EmmiterNode>(Particle::Propellant);
		propellant->setPosition(0.f, getBoundingRect().height / 2.f);
		attachChild(std::move(propellant));
	}
}

void Projectile::guideTowards(sf::Vector2f position)
{
	assert(isGuided());
	mTargetDirection = unitVector(position - getWorldPosition());
}

bool Projectile::isGuided() const
{
	return mType == Missile;
}

unsigned int Projectile::getCategory() const
{
	if(mType == EnemyBullet)
		return Category::EnemyProjectile;
	else
		return Category::AlliedProjectile;
}

sf::FloatRect Projectile::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

float Projectile::getMaxSpeed() const
{
	return Table[mType].speed;
}

int Projectile::getDamage() const
{
	return Table[mType].damage;
}

void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if(isGuided())
	{
		const float approachRate = 200.f;
		sf::Vector2f newVelocity = unitVector(approachRate * dt.asSeconds() * mTargetDirection + getVelocity());
		newVelocity *= getMaxSpeed();
		float angle = std::atan2(newVelocity.y, newVelocity.x);

		setRotation(toDegree(angle) + 90.f);
		setVelocity(newVelocity);
	}

	Entity::updateCurrent(dt, commands);
}

void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}


