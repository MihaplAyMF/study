#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.h"
#include "CommandQueue.h"
#include "ResourceIdentifiers.h"
#include "Projectile.h"
#include "TextNode.h"
#include "Animation.h"

class Aircraft : public Entity
{
public:
	
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,
		TypeCount
	};

	explicit				Aircraft(Type type, const TextureHolder& textures, FontHolder& fonts);
	
	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;
	virtual void			remove();
	virtual bool			isMarkedForRemoval() const;
	bool					isAllied() const;
	float					getMaxSpeed() const;
	void					disablePickups();

	void					increaseFireRate();
	void					increaseSpread();
	void					collectMissile(unsigned int count);

	void					fire();
	void					launchMissile();
	void					playLocalSound(CommandQueue& commands, SoundEffect effect);
	int						getIdentifier();
	void					setIdentifier(int identifier);
	int						getMissileAmmo() const;
	void					setMissileAmmo(int ammo);

private:
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);

	void					updateMovementPattern(sf::Time dt);
	void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);
	void					checkPickupDrop(CommandQueue& commands);

	void					createBullets(SceneNode& node, const TextureHolder& texture) const;
	void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float y0ffset, const TextureHolder& textures) const;
	void					createPickup(SceneNode& node, const TextureHolder& textures) const;

	void					updateTexts();	
	void					updateRollAnimation();


	Type		mType;
	sf::Sprite	mSprite;
	Animation	mExplosion;	
	sf::Time	mFireCountdown;
	Command		mFireCommand;
	Command		mMissileCommand;
	Command 	mDropPickupCommand;

	TextNode*	mHealthDisplay;
	TextNode*	mMissileDisplay;
	std::size_t mDirectionIndex;

	bool		mIsFiring;
	bool		mIsLaunchingMissile;		
	bool 		mShowExplosion;
	bool		mExplosionBegan;
	bool		mSpawnedPickup;
	bool		mPickupsEnabled;

	int			mFireRateLevel;
	int			mSpreadLevel;
	int			mMissileAmmo;
	int			mIdentifier;

	float		mTravelledDistance;
	
};
