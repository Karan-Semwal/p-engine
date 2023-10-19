#pragma once

class GameState;
namespace sf {
    class RenderWindow;
}

class GameStateManager
{
public:
    void update();
    void render(sf::RenderWindow& window);
    GameStateManager* getInstance();

private:
    GameStateManager();
    ~GameStateManager();
    GameStateManager(const GameStateManager&) = delete;

private:
    GameState* m_gameState;
};