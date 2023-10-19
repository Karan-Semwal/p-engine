#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameState
{
public:
    GameState() = default;
    virtual ~GameState() = default;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

private:
};
