#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

class Animation : public sf::Drawable, public sf::Transformable
{
public:
					   Animation();
	explicit		   Animation(const sf::Texture& texture);

	void			   setTexture(const sf::Texture& texture);
	const sf::Texture* getTexture() const;

	void			   setFrameSize(sf::Vector2i frameSize);
	sf::Vector2i	   getFrameSize() const;

	void			   setNumFrames(size_t numFrames);
	size_t			   getNumFrames() const;
	
	void			   setDuration(sf::Time duration);
	sf::Time		   getDuration() const;

	void			   setRepeating(bool flag);
	bool			   getRepeating() const;

	void			   restart();
	bool			   isFinished() const;

	sf::FloatRect      getLocalBounds() const;
	sf::FloatRect	   getGlobalBound() const;

	void			   update(sf::Time dt);

private:
	void			   draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite	 mSprite;
	sf::Vector2i mFrameSize;
	size_t		 mNumFrames;
	size_t		 mCurrentFrame;
	sf::Time	 mDuration;
	sf::Time	 mElapsedTime;
	bool		 mRepeat;
};