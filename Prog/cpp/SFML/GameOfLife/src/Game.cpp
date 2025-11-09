#include "Game.h"

const sf::Time Game::timePerFrame = sf::seconds(1.f / 15.f);

Game::Game()
    : mWindow(sf::VideoMode({1024, 768}), "Game of Life", sf::Style::Titlebar | sf::Style::Close) 
    , mState(mWindow)
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while(mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while(timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            handleInput();
            update(timePerFrame);
        }
        render();
    }  
}

void Game::handleInput()
{
	while(const std::optional event = mWindow.pollEvent())
	{            
        mState.handle(*event);
        if (event->is<sf::Event::Closed>())
        {
            mWindow.close();
        }
    }

}

void Game::update(sf::Time dt)
{
    mState.update();
    
}

void Game::render() 
{
    mWindow.clear();
    mState.render(); 
    mWindow.display();
}
