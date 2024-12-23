#include <SFML/Graphics/RenderWindow.hpp>

#include "TitleState.h"
#include "Utility.hpp"
#include "ResourceHolder.hpp"

TitleState::TitleState(StateStack& stack, Context context)
    : State(stack, context)
    , mText()
    , mShowText(true)
    , mTextEffectTime(sf::Time::Zero)
{ 
    mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

    mText.setFont(context.fonts->get(Fonts::Main));
    mText.setString("Press any key to start");
    centerOrigin(mText);
    mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));
}

bool TitleState::handleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::KeyReleased)
    {
        requestStackPop();
        requestStackPush(States::Menu);
    }

    return true;
}

bool TitleState::update(sf::Time dt)
{
    mTextEffectTime += dt;

    if(mTextEffectTime >= sf::seconds(0.5f))
    {
        mShowText = !mShowText;
        mTextEffectTime = sf::Time::Zero;
    }

    return false;
}

void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(mBackgroundSprite);

    if(mShowText)
        window.draw(mText);
}
