#pragma once

#include "SceneNode.h"
#include "ResourceIdentifiers.h"

class SoundPlayer;

class SoundNode : public SceneNode
{
public:
	explicit				SoundNode(SoundPlayer& player);
	void					playSound(SoundEffect sound, sf::Vector2f position);

	virtual unsigned int    getCategory() const override;

private:
	SoundPlayer& mSounds;
};