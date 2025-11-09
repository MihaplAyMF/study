#include "Animation.h"

Animator::Animator(sf::Sprite& sprite)
	: m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr)
{ }

Animator::Animation& Animator::createAnimation(std::string const& name, 
	std::string const& textureName, sf::Time const& duration, bool loop)
{
	m_Animations.push_back(
		Animator::Animation(name, textureName, duration, loop));

	if(m_CurrentAnimation == nullptr)
		switchAnimation(&m_Animations.back());
	
	return m_Animations.back();
}

void Animator::update(sf::Time const& dt)
{
	if(m_CurrentAnimation == nullptr)
		return;
	
	m_CurrentTime += dt;
	
	float scaleTime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
	int numFrames = m_CurrentAnimation->m_Frames.size();
	int currentFrame = static_cast<int>(scaleTime * numFrames);

	if(m_CurrentAnimation->m_Looping)
		currentFrame %= numFrames;
	else if(currentFrame >= numFrames)
		currentFrame = numFrames - 1;

	m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);

}

bool Animator::switchAnimation(std::string const& name)
{
	auto animation = findAnimation(name);
	if(animation != nullptr)
	{
		switchAnimation(animation);
		return true;
	}
	return false;
}

std::string Animator::getCurretnAnimationName() const
{
	if(m_CurrentAnimation != nullptr)
		return m_CurrentAnimation->m_Name;

	return "";
}

Animator::Animation* Animator::findAnimation(std::string const& name)
{
	for(auto it = m_Animations.begin(); it != m_Animations.end(); ++it)
	{
		if(it->m_Name == name)
			return &*it;
	}

	return nullptr;
}

void Animator::switchAnimation(Animator::Animation* animation)
{
	if(animation != nullptr)
	{
		m_Sprite.setTexture(AssetManager::getTexture(animation->m_TextureName));
	}

	m_CurrentAnimation = animation;
	m_CurrentTime = sf::Time::Zero;
}
