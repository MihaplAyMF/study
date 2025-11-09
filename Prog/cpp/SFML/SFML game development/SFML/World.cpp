#include <algorithm>
#include <cmath>
#include <limits>

#include <SFML/Graphics/RenderWindow.hpp>
#include "World.h"
#include "Projectile.h"
#include "TextNode.h"
#include "SoundNode.h"
#include "Pickup.h"
#include "ParticleNode.h"
#include "BloomEffect.h"

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2) 
{
	unsigned int category1 = colliders.first->getCategory();
	unsigned int category2 = colliders.second->getCategory();

	if(type1 & category1 && type2 & category2)
	{
		return true;
	} 
	else if(type1 & category2 && type2 & category1)
	{
		std::swap(colliders.first, colliders.second);
		return true;
	}
	else
	{
		return false;
	}
}

World::World(sf::RenderWindow& outputTarget, FontHolder& fonts, SoundPlayer& sounds, bool networked)
	: mTarget(outputTarget)
	, mSceneTexture()
	, mWorldView(outputTarget.getDefaultView())
	, mTextures()
	, mFonts(fonts)
	, mSounds(sounds)
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 6000.f)
	, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, mScrollSpeedCompensation(1.f)
	, mPlayerAircrafts()
	, mEnemySpawnPoints()
	, mActiveEnemies()
	, mNetworkedWorld(networked)
	, mNetworkNode(nullptr)
	, mFinishSprite(nullptr)
{ 
	mSceneTexture.create(mTarget.getSize().x, mTarget.getSize().y);

	loadTextures();
	buildScene();
	
	mWorldView.setCenter(mSpawnPosition);
}

void World::setWorldScrollCompensation(float compensation)
{
	mScrollSpeedCompensation = compensation;
}

void World::update(sf::Time dt)
{
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	
	for(Aircraft* a : mPlayerAircrafts)
		a->setVelocity(0.f, 0.f);
	
	destroyEntitiesOutsideView();
	guideMissiles();

	while(!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);

	adaptPlayerVelocity();

	handleCollisions();

	auto firstToRemove = std::remove_if(mPlayerAircrafts.begin(), mPlayerAircrafts.end(), std::mem_fn(&Aircraft::isMarkedForRemoval));
	mPlayerAircrafts.erase(firstToRemove, mPlayerAircrafts.end());

	mSceneGraph.removeWrecks();
	spawnEnemies();
	
	mSceneGraph.update(dt, mCommandQueue);
	adaptPlayerPosition();

	updateSounds();
}

void World::draw()
{
	if(PostEffect::isSupported())
	{
		mSceneTexture.clear();
		mSceneTexture.setView(mWorldView);
		mSceneTexture.draw(mSceneGraph);
		mSceneTexture.display();
		mBloomEffect.apply(mSceneTexture, mTarget);
	} 
	else
	{
		mTarget.setView(mWorldView);
		mTarget.draw(mSceneGraph);
	}
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

Aircraft* World::addAircraft(int identifier)
{
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, mTextures, mFonts));
	player->setPosition(mWorldView.getCenter());
	player->setIdentifier(identifier);

	mPlayerAircrafts.push_back(player.get());
	mSceneLayers[UpperAir]->attachChild(std::move(player));
	return mPlayerAircrafts.back();
}

void World::removeAircraft(int identifier)
{
	Aircraft* aircraft = getAircraft(identifier);
	if(aircraft)
	{
		aircraft->destroy();
		mPlayerAircrafts.erase(std::find(mPlayerAircrafts.begin(), mPlayerAircrafts.end(), aircraft));
	}
}

void World::setCurrentBattleFieldPosition(float lineY)
{
	mWorldView.setCenter(mWorldView.getCenter().x, lineY - mWorldView.getSize().y / 2);
	mSpawnPosition.y = mWorldBounds.height;
}

void World::setWorldHeight(float height)
{
	mWorldBounds.height = height;
}

bool World::hasAlivePlayer() const
{
	return mPlayerAircrafts.size() > 0;
}

bool World::hasPlayerReachedEnd() const
{
	if(Aircraft* aircraft = getAircraft(1))
		return !mWorldBounds.contains(aircraft->getPosition());
	else
		return false;
}

void World::loadTextures()
{
	mTextures.load(Textures::Entities,   "Media/Textures/Entities.png");
	mTextures.load(Textures::Jungle,     "Media/Textures/Jungle.png");
	mTextures.load(Textures::Explosion,  "Media/Textures/Explosion.png");
	mTextures.load(Textures::Particle,   "Media/Textures/Particle.png");
	mTextures.load(Textures::FinishLine, "Media/Textures/FinishLine.png");
}

void World::buildScene()
{
	for(std::size_t i = 0; i < LayerCount; i++)
	{
		Category::Type category = (i == LowerAir) ? Category::SceneAirLayer : Category::None;

		SceneNode::Ptr layer = std::make_unique<SceneNode>(category);
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& jungleTexture = mTextures.get(Textures::Jungle);
	jungleTexture.setRepeated(true);

	float viewHeight = mWorldView.getSize().y;
	sf::IntRect textureRect(mWorldBounds);
	textureRect.height += static_cast<int>(viewHeight);

	std::unique_ptr<SpriteNode> jungleSprite =
		std::make_unique<SpriteNode>(jungleTexture, textureRect);
	jungleSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(jungleSprite));
	
	sf::Texture& finishTexture = mTextures.get(Textures::FinishLine);
	std::unique_ptr<SpriteNode> finishSprite(new SpriteNode(finishTexture));
	finishSprite->setPosition(0.f, -76.f);
	mSceneLayers[Background]->attachChild(std::move(finishSprite));

	std::unique_ptr<ParticleNode> smokeNode = std::make_unique<ParticleNode>(Particle::Smoke, mTextures);
	mSceneLayers[LowerAir]->attachChild(std::move(smokeNode));

	std::unique_ptr<ParticleNode> propellantNode = std::make_unique<ParticleNode>(Particle::Propellant, mTextures);
	mSceneLayers[LowerAir]->attachChild(std::move(propellantNode));

	std::unique_ptr<SoundNode> soundNode(new SoundNode(mSounds));
	mSceneGraph.attachChild(std::move(soundNode));

	if(mNetworkedWorld)
	{
		std::unique_ptr<NetworkNode> networkNode(new NetworkNode());
		mNetworkNode = networkNode.get();
		mSceneGraph.attachChild(std::move(networkNode));
	}

	addEnemies();
}

void World::adaptPlayerPosition()
{
	sf::FloatRect viewBounds = getViewBounds();
	const float borderDistance = 40.f;

	for(Aircraft* aircraft : mPlayerAircrafts)
	{
		sf::Vector2f position = aircraft->getPosition();
		position.x = std::max(position.x, viewBounds.left + borderDistance);
		position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
		position.y = std::max(position.y, viewBounds.top + borderDistance);
		position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
		aircraft->setPosition(position);
	}
}

void World::adaptPlayerVelocity()
{
	for(Aircraft* aircraft : mPlayerAircrafts)
	{
		sf::Vector2f velocity = aircraft->getVelocity();

		if(velocity.x != 0 && velocity.y != 0)
			aircraft->setVelocity(velocity / std::sqrt(2.f));

		aircraft->accelerate(0.f, mScrollSpeed);
	}
}

void World::handleCollisions()
{
	std::set<SceneNode::Pair> colisionPairs;
	mSceneGraph.checkSceneCollision(mSceneGraph, colisionPairs);

	for(SceneNode::Pair pair : colisionPairs)
	{
		if(matchesCategories(pair, Category::PlayerAircraft, Category::EnemyAircraft))
		{
			auto& player = static_cast<Aircraft&>(*pair.first);
			auto& enemy = static_cast<Aircraft&>(*pair.second);

			player.damage(enemy.getHitpoints());
			enemy.destroy();
		}
		else if(matchesCategories(pair, Category::PlayerAircraft, Category::Pickup))
		{
			auto& player = static_cast<Aircraft&>(*pair.first);
			auto& pickup = static_cast<Pickup&>(*pair.second);

			pickup.apply(player);
			pickup.destroy();				
			player.playLocalSound(mCommandQueue, SoundEffect::CollectPickup);
		}
		else if(matchesCategories(pair, Category::EnemyAircraft, Category::AlliedProjectile)
			|| matchesCategories(pair, Category::PlayerAircraft, Category::EnemyProjectile))
		{
			auto& aircraft = static_cast<Aircraft&>(*pair.first);
			auto& projecttile = static_cast<Projectile&>(*pair.second);

			aircraft.damage(projecttile.getDamage());
			projecttile.destroy();
		}
	}
}

void World::updateSounds()
{
	sf::Vector2f listenerPosition;

	if(mPlayerAircrafts.empty())
	{
		listenerPosition = mWorldView.getCenter();
	}

	else
	{
		for(Aircraft* aircraft : mPlayerAircrafts)
			listenerPosition += aircraft->getWorldPosition();

		listenerPosition /= static_cast<float>(mPlayerAircrafts.size());
	}

	mSounds.setListenerPosition(listenerPosition);
	mSounds.removeStoppedSounds();
}

void World::spawnEnemies()
{
	while(!mEnemySpawnPoints.empty()
		&& mEnemySpawnPoints.back().y > getBattlefieldBounds().top)
	{
		SpawnPoint spawn = mEnemySpawnPoints.back();

		std::unique_ptr<Aircraft> enemy = std::make_unique<Aircraft>(spawn.type, mTextures, mFonts);
		enemy->setPosition(spawn.x, spawn.y);
		enemy->setRotation(180.f);

		mSceneLayers[UpperAir]->attachChild(std::move(enemy));
		
		mEnemySpawnPoints.pop_back();
	}
}

void World::destroyEntitiesOutsideView()
{
	Command command;
	command.category = Category::Projectile | Category::EnemyAircraft;
	command.action = derivedAction<Entity>([this](Entity& e, sf::Time)
	{
		if(!getBattlefieldBounds().intersects(e.getBoundingRect()))
			e.remove();
	});
	mCommandQueue.push(command);
}

void World::addEnemy(Aircraft::Type type, float relX, float relY)
{
	SpawnPoint spawn(type, mSpawnPosition.x + relX, mSpawnPosition.y - relY);
	mEnemySpawnPoints.push_back(spawn);
}

void World::sortEnemies()
{
	std::sort(mEnemySpawnPoints.begin(), mEnemySpawnPoints.end(), [] (SpawnPoint lhs, SpawnPoint rhs)
	{
		return lhs.y < rhs.y;
	});
}

void World::guideMissiles()
{
	Command enemyCollector;
	enemyCollector.category = Category::EnemyAircraft;
	enemyCollector.action = derivedAction<Aircraft>([this] (Aircraft& enemy, sf::Time)
	{
		if(!enemy.isDestroyed())
			mActiveEnemies.push_back(&enemy);
	});

	Command missileGuider;
	missileGuider.category = Category::AlliedProjectile;
	missileGuider.action = derivedAction<Projectile>([this] (Projectile& missile, sf::Time) 
	{
		if(!missile.isGuided())
			return;
		
		float minDistance = std::numeric_limits<float>::max();
		Aircraft* closestEnemy = nullptr;

		for(Aircraft* enemy : mActiveEnemies)
		{
			float enemyDistance = distance(missile, *enemy);

			if(enemyDistance < minDistance)
			{
				closestEnemy = enemy;
				minDistance = enemyDistance;
			}
		}
		if(closestEnemy)
			missile.guideTowards(closestEnemy->getWorldPosition());
	});

	mCommandQueue.push(enemyCollector);
	mCommandQueue.push(missileGuider);
	mActiveEnemies.clear();
}

void World::addEnemies()
{
	for(int i = 0; i < 40; i++)
	{
		if(i % 2 == 0)
		{
			addEnemy(Aircraft::Raptor, -100.f, 400.f + (100.f * i));
			addEnemy(Aircraft::Raptor, +100.f, 400.f + (100.f * i));
		}
		else
		{
			addEnemy(Aircraft::Avenger, -100.f, 400.f + (100.f * i));
			addEnemy(Aircraft::Avenger, +100.f, 400.f + (100.f * i));
		}
	}
	
	sortEnemies();
}

sf::FloatRect World::getViewBounds() const
{
	return sf::FloatRect(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
}

Aircraft* World::getAircraft(int identifier) const
{
	for(Aircraft* a : mPlayerAircrafts)
	{
		if(a->getIdentifier() == identifier)
			return a;
	}

	return nullptr;
}

sf::FloatRect World::getBattlefieldBounds() const
{
	sf::FloatRect bounds = getViewBounds();

	bounds.top -= 100.f;
	bounds.height += 200.f;

	return bounds;
}

void World::createPickup(sf::Vector2f position, Pickup::Type type)
{
	std::unique_ptr<Pickup> pickup(new Pickup(type, mTextures));
	pickup->setPosition(position);
	pickup->setVelocity(0.f, 1.f);
	mSceneLayers[UpperAir]->attachChild(std::move(pickup));
}

bool World::pollGameAction(GameActions::Action& out)
{
	return mNetworkNode->pollGameAction(out);
}