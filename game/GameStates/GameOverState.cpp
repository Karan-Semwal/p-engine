#include "GameOverState.h"
#include "GamePlayState.h"
#include "MainMenuState.h"
#include "pengine.h"
#include <SFML/Graphics/RectangleShape.hpp>

GameOverState::GameOverState(sf::RenderWindow &window)
    : GameState(window)
{
    m_background = new sf::RectangleShape{};
    m_replay = new Button{*this->m_window, *m_replayButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y - 50, 100, 50};
    m_exit = new Button{*this->m_window, *m_exitButtonTextureAddress, WINDOW_CENTER_X, WINDOW_CENTER_Y + 50, 100, 50};
    init();
}

GameOverState::~GameOverState()
{
    delete m_background;
    delete m_replay;
    delete m_exit;
}

GameState *GameOverState::update()
{
    if (m_replay->isClicked())
    {
        // reset the game -> play again
        return new GamePlayState{*this->m_window};
    }
    if (m_exit->isClicked())
    {
        // Switch to Main Menu State
        return new MainMenuState{*this->m_window};
    }
    return nullptr;
}

void GameOverState::render(sf::RenderWindow &window)
{
    window.draw(*m_background);
    m_replay->render(window);
    m_exit->render(window);
}

void GameOverState::init()
{
    m_background->setSize({WINDOW_WIDTH, WINDOW_HEIGHT});
    // Color
    m_background->setFillColor(randomColor());
    m_replay->getButtonObject().setFillColor(randomColor());
    m_exit->getButtonObject().setFillColor(randomColor());
}