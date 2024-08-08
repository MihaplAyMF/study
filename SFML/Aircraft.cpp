#include <cmath>
#include <string>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Aircraft.h"
#include "DataTables.h"
#include "Utility.hpp"
#include "CommandQueue.h"
#include "SoundNode.h"
#include "ResourceHolder.hpp"
#include "Pickup.h"
#include "NetworkNode.h"
#include "NetworkProtocol.h"

namespace
{
	const std::vector<AircraftData> Table = initializeAircraftData();
}

// constructor
Aircraft::Aircraft(Type type, const TextureHolder& textures, FontHolder& fonts)
	: Entity(Table[type].hitpoints)
	, mType(type)
	, mSprite(textures.get(Table[type].texture), Table[type].textureRect)
	, mExplosion(textures.get(Textures::Explosion))
	, mFireCommand()
	, mMissileCommand()
	, mFireCountdown(sf::Time::Zero)
	, mIsFiring(false)
	, mIsLaunchingMissile(false)
	, mShowExplosion(true)
	, mExplosionBegan(false)
	, mSpawnedPickup(false)
	, mPickupsEnabled(true)
	, mFireRateLevel(1)
	, mMissileAmmo(2)
	, mSpreadLevel(1)
	, mTravelledDistance(0.f)
	, mDirectionIndex(0)
	, mMissileDisplay(nullptr)
	, mIdentifier(0)
{
	mExplosion.setFrameSize(sf::Vector2i(256, 256));
	mExplosion.setNumFrames(16);
	mExplosion.setDuration(sf::seconds(1));

	centerOrigin(mSprite);
	centerOrigin(mExplosion);

	mFireCommand.category = Category::SceneAirLayer;
	mFireCommand.action   = [this, &textures](SceneNode& node, sf::Time)
	{
		createBullets(node, textures);
	};

	mMissileCommand.category = Category::SceneAirLayer;
	mMissileCommand.action   = [this, &textures](SceneNode& node, sf::Time)
	{
		createProjectile(node, Projectile::Missile, 0.f, 0.5f, textures);
	};

	mDropPickupCommand.category = Category::SceneAirLayer;
	mDropPickupCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createPickup(node, textures);
	};

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	
	std::unique_ptr<TextNode> healthDisplay = std::make_unique<TextNode>(fonts, "");
	mHealthDisplay = healthDisplay.get();
	attachChild(std::move(healthDisplay));

	if(getCategory() == Category::PlayerAircraft)
	{
		std::unique_ptr<TextNode> missileDisplay(new TextNode(fonts, ""));
		missileDisplay->setPosition(0, 70);
		mMissileDisplay = missileDisplay.get();
		attachChild(std::move(missileDisplay));
	}

	updateTexts();
}

// draw method
void Aircraft::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	if(isDestroyed() && mShowExplosion)
		target.draw(mExplosion, states);
	else
		target.draw(mSprite, states);
}

// get methods
unsigned int Aircraft::getCategory() const
{
	if(isAllied())
		return Category::PlayerAircraft;
	else
		return Category::EnemyAircraft;
}

sf::FloatRect Aircraft::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

bool Aircraft::isMarkedForRemoval() const
{
	return isDestroyed() && (mExplosion.isFinished() || !mShowExplosion);
}

bool Aircraft::isAllied() const
{
	return mType == Eagle;
}

float Aircraft::getMaxSpeed() const
{	
	return Table[mType].speed;
}

int	Aircraft::getIdentifier()
{
	return mIdentifier;
}

int Aircraft::getMissileAmmo() const
{
	return mMissileAmmo;
}

// update methods

void Aircraft::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	updateTexts();
	updateRollAnimation();

	if(isDestroyed())
	{
		checkPickupDrop(commands);
		mExplosion.update(dt);

		if(!mExplosionBegan)
		{
			SoundEffect soundEffect = (randomInt(2) == 0) ? SoundEffect::Explosion1 : SoundEffect::Explosion2;
			playLocalSound(commands, soundEffect);

			if(!isAllied())
			{
				sf::Vector2f position = getWorldPosition();

				Command command;
				command.category = Category::Network;
				command.action = derivedAction<NetworkNode>([position] (NetworkNode& node, sf::Time)
				{
					node.notifyGameAction(GameActions::EnemyExplode, position);
				});

				commands.push(command);
			}

			mExplosionBegan = true;
		}

		return;
	}
	checkProjectileLaunch(dt, commands);

	updateMovementPattern(dt);
	Entity::updateCurrent(dt, commands);
}

void Aircraft::updateTexts()
{
	if(isDestroyed())
		mHealthDisplay->setString("");
	else
		mHealthDisplay->setString(toString(getHitpoints()) + " HP");
	mHealthDisplay->setPosition(0.f, 50.f);
	mHealthDisplay->setRotation(-getRotation());

	if(mMissileDisplay)
	{
		if(mMissileAmmo == 0)
			mMissileDisplay->setString("");
		else
			mMissileDisplay->setString("M: " + toString(mMissileAmmo));
	}
}

void Aircraft::updateRollAnimation()
{
	if(Table[mType].hasRollAnimation)
	{
		sf::IntRect textureRect = Table[mType].textureRect;
		
		if(getVelocity().x < 0.f)
			textureRect.left += textureRect.width;
		else if(getVelocity().x > 0.f)
			textureRect.left += 2 * textureRect.width;

		mSprite.setTextureRect(textureRect);
	}
}

void Aircraft::updateMovementPattern(sf::Time dt)
{
	const std::vector<Direction>& directions = Table[mType].directions;

	if(!directions.empty())
	{
		float distanceToTravel = directions[mDirectionIndex].distance;
		if(mTravelledDistance > distanceToTravel)
		{
			mDirectionIndex = (mDirectionIndex + 1) % directions.size();
			mTravelledDistance = 0.f;
		}
		float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
		float vx = getMaxSpeed() * std::cos(radians);
		float vy = getMaxSpeed() * std::sin(radians);
		setVelocity(vx, vy);
		setVelocity(vx, vy);

		mTravelledDistance += getMaxSpeed() * dt.asSeconds();
	}
}

// check methods
void Aircraft::checkProjectileLaunch(sf::Time dt, CommandQueue& commands)
{
	if(!isAllied())
		fire();
	
	if(mIsFiring && mFireCountdown <= sf::Time::Zero)
	{
		commands.push(mFireCommand); 
		playLocalSound(commands, isAllied() ? SoundEffect::AlliedGunfire : SoundEffect::EnemyGunfire);

		mFireCountdown += Table[mType].fireInterval / (mFireRateLevel + 1.f);
		mIsFiring = false;	
	}
	else if(mFireCountdown > sf::Time::Zero)
	{
		mFireCountdown -= dt;
		mIsFiring = false;
	}
	
	if(mIsLaunchingMissile)
	{
		commands.push(mMissileCommand);
		playLocalSound(commands, SoundEffect::LaunchMissile);

		mIsLaunchingMissile = false;
	}
}

void Aircraft::checkPickupDrop(CommandQueue& commands)
{
	if(!isAllied() && randomInt(3) == 0 && !mSpawnedPickup)
		commands.push(mDropPickupCommand);
	
	mSpawnedPickup = true;
}

void Aircraft::remove()
{
	Entity::remove();
 	mShowExplosion = false;
}

// create methods
void Aircraft::createBullets(SceneNode& node, const TextureHolder& texture) const
{
	Projectile::Type type = isAllied() ? Projectile::AlliedBullet : Projectile::EnemyBullet;

	switch(mSpreadLevel)
	{
	case 1:
		createProjectile(node, type, +0.0f, 0.5f, texture);
		break;
	case 2:
		createProjectile(node, type, -0.33f, 0.33f, texture);
		createProjectile(node, type, +0.33f, 0.33f, texture);
		break;
	case 3:		
		createProjectile(node, type, -0.5f, 0.33f, texture);
		createProjectile(node, type, +0.0f, 0.5f, texture);
		createProjectile(node, type, +0.5f, 0.33f, texture);
		break;
	}
}

void Aircraft::createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float y0ffset, const TextureHolder& textures) const
{
	std::unique_ptr<Projectile> projectile = std::make_unique<Projectile>(type, textures);

	sf::Vector2f offset(xOffset * mSprite.getGlobalBounds().width, y0ffset * mSprite.getGlobalBounds().height);
	sf::Vector2f velocity(0, projectile->getMaxSpeed());

	float sign = isAllied() ? -1.f : +1.f;

	projectile->setPosition(getWorldPosition() + offset * sign);
	projectile->setVelocity(velocity * sign);
	node.attachChild(std::move(projectile));
}

void Aircraft::createPickup(SceneNode& node, const TextureHolder& textures) const
{
	auto type = static_cast<Pickup::Type>(randomInt(Pickup::TypeCount));

	std::unique_ptr<Pickup> pickup = std::make_unique<Pickup>(type, textures);
	pickup->setPosition(getWorldPosition());
	pickup->setVelocity(0.f, 1.f);
	node.attachChild(std::move(pickup));
}

// upgrade methods
void Aircraft::increaseFireRate()
{
	if(mFireRateLevel < 10)
		mFireRateLevel++;
}

void Aircraft::increaseSpread()
{
	if(mSpreadLevel < 3)
		mSpreadLevel++;
}

void Aircraft::collectMissile(unsigned int count)
{
	mMissileAmmo += count;
}

// command methods
void Aircraft::fire()
{
	if(Table[mType].fireInterval != sf::Time::Zero)  
		mIsFiring = true;	
}

void Aircraft::launchMissile()
{
	if(mMissileAmmo > 0)
		mIsLaunchingMissile = true;
}

void Aircraft::playLocalSound(CommandQueue& commands, SoundEffect effect)
{
	sf::Vector2f worldPosition = getWorldPosition();
	
	Command command;
	command.category = Category::SoundEffect;
	command.action = derivedAction<SoundNode>(
		[effect, worldPosition] (SoundNode& node, sf::Time)
	{
		node.playSound(effect, worldPosition);
	});

	commands.push(command);
}


void Aircraft::setIdentifier(int identifier)
{
	mIdentifier = identifier;
}

void Aircraft::setMissileAmmo(int ammo)
{
	mMissileAmmo = ammo;
}

void Aircraft::disablePickups()
{
	mPickupsEnabled = false;
}