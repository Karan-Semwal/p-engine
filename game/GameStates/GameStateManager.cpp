#include "GameStateManager.h"
#include "MainMenuState.h"

GameStateManager::GameStateManager()
{
    m_gameState = new MainMenuState();
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

GameStateManager* GameStateManager::getInstance()
{
    static GameStateManager* gameStateManagerInstance = new GameStateManager();
    return gameStateManagerInstance;
}