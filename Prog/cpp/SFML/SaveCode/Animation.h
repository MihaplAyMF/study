#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Animator
{
public:
	struct Animation
	{
		std::string m_Name;
		std::string m_TextureName;
		std::vector<sf::IntRect> m_Frames;
		sf::Time m_Duration;
		bool m_Looping;

		Animation(std::string const& name, std::string const& textureName,
			sf::Time const& duration, bool looping)
			: m_Name(name), m_TextureName(textureName),
			m_Duration(duration), m_Looping(looping)
		{ }

		void AddFrames(sf::Vector2i const& startFrom,
			sf::Vector2i const& frameSize, unsigned int frames)
		{
			sf::Vector2i current = startFrom;
			for(unsigned int i = 0; i < frames; i++)
			{
				m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
				current.x += frameSize.x;
			}
		}
	};

	Animator(sf::Sprite& sprite);

	Animator::Animation& createAnimation(std::string const& name,
		std::string const& textureName, sf::Time const& duration, bool loop = false);

	void update(sf::Time const& dt);

	bool switchAnimation(std::string const& name);

	std::string getCurretnAnimationName() const;

private:

	Animator::Animation* findAnimation(std::string const& name);

	void switchAnimation(Animator::Animation* animation);

	sf::Sprite& m_Sprite;
	sf::Time m_CurrentTime;
	std::list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;

};