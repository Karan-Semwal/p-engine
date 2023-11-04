#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameState
{
public:
    GameState() = delete;
    GameState(sf::RenderWindow &window) : m_window(&window)
    {
    }
    virtual ~GameState() = default;

    virtual GameState *update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;

protected:
    sf::RenderWindow *m_window;
};
