#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <vector>

class GameState {
public:
    GameState(sf::RenderWindow& window);
    ~GameState();
    
    void handle(const sf::Event& event);
    void update();
    void render();
    
private:
    void drawGrid();
    int countNeighbors(int x, int y); 

    sf::RenderWindow& mWindow;

    std::vector<int> mCellSizeOptions;
    int mSelectedCellSizeIndex;
    float mCellSize;

    int mGridWidth;
    int mGridHeight;
    int cols, rows;

    std::vector<std::vector<bool>> grid;  
    std::vector<std::vector<bool>> nextGrid; 
    
    sf::Clock deltaClock;
    bool mIsRunning; 
};
