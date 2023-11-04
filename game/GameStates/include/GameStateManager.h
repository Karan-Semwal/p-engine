#pragma once

class GameState;
namespace sf
{
    class RenderWindow;
}

class GameStateManager
{
public:
    void update();
    void render(sf::RenderWindow &window);
    static GameStateManager *getInstance(sf::RenderWindow &window);

private:
    GameStateManager(sf::RenderWindow &window);
    ~GameStateManager();
    GameStateManager(const GameStateManager &) = delete;

private:
    GameState *m_gameState;
};