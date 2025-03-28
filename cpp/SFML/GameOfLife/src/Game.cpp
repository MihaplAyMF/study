#include "Game.h"

#include <cstdlib>
#include <imgui-SFML.h>

const sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
{
    mWindow.create(sf::VideoMode({1024, 768}), "Game of Life", sf::Style::Default);
    if(!ImGui::SFML::Init(mWindow))
        abort();
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
        if (event->is<sf::Event::Closed>())
        {
            mWindow.close();
        }
    }

}

void Game::update(sf::Time dt)
{
    
}

void Game::render() 
{
    mWindow.clear();
    mWindow.display();
}
