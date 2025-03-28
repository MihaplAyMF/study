#pragma ocne

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    void handleInput();
    void update(sf::Time dt);
    void render();
    
private:
    static const sf::Time timePerFrame;

    sf::RenderWindow mWindow;
};
