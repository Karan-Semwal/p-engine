#include "GameStateManager.h"
#include "MainMenuState.h"

GameStateManager::GameStateManager(sf::RenderWindow& window)
{
    m_gameState = new MainMenuState(window);
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::update()
{
    m_gameState->update();
}

void GameStateManager::render(sf::RenderWindow& window)
{
    m_gameState->render(window);
}

// only one game state manager can exist for one window object
GameStateManager* GameStateManager::getInstance(sf::RenderWindow& window)
{
    static GameStateManager* gameStateManagerInstance = new GameStateManager(window);
    return gameStateManagerInstance;
}