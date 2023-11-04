#include "GameStateManager.h"
#include "MainMenuState.h"

GameStateManager::GameStateManager(sf::RenderWindow &window)
{
    m_gameState = new MainMenuState(window);
}

GameStateManager::~GameStateManager()
{
    delete m_gameState;
}

void GameStateManager::update()
{
    GameState *nextState = m_gameState->update();
    if (nextState != nullptr) // state change took place
    {
        // switch betweem game states based on events from current/active game state
        this->m_gameState = nextState;
    }
}

void GameStateManager::render(sf::RenderWindow &window)
{
    m_gameState->render(window);
}

// only one game state manager can exist for one window object
GameStateManager *GameStateManager::getInstance(sf::RenderWindow &window)
{
    static GameStateManager *gameStateManagerInstance = new GameStateManager(window);
    return gameStateManagerInstance;
}