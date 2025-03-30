#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

class GameState {
public:
    GameState(sf::RenderWindow& window);
    ~GameState();
    
    void handle(const sf::Event& event);
    void update();
    void render();

private:
    sf::RenderWindow& mWindow;
    sf::RectangleShape cell;

    float mCellSize;

    sf::Clock deltaClock;
    bool showUI = true;
};
